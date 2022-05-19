#pragma once

#include <dds/dds.hpp>
#include <map>
#include <thread>
#include <mutex>
#include <functional>
//#include <ppltasks.h>

namespace DDS
{
    namespace Comm
    {
        template <class T>
        class ReaderListener : public dds::sub::NoOpDataReaderListener <T>
        {
            public:

                ReaderListener() { }

				using EventAction = std::function <void(std::vector<T> updated_data, std::vector<T> deleted_data)>;

				virtual void on_data_available(dds::sub::DataReader<T>& reader) override;

				int RegisterOnData(EventAction callback);

				void UnregisterFromData(int index);

			protected:

				std::map<int, EventAction> m_callbacks_map;
				int m_last_ind = 0;
				std::mutex m_mutex;
				std::thread m_event_thread;
		};
	}
}

template <class T>
void DDS::Comm::ReaderListener<T>::on_data_available(dds::sub::DataReader<T>& reader)
{
	if (m_callbacks_map.size() <= 0)
	{
		return;
	}

	// Take all samples
	// take() returns a sequence of samples for all of the instances in the system 
	dds::sub::LoanedSamples<T> samples = reader.take();

	std::vector<T> updated_data;
	std::vector<T> deleted_data;

	// Traverse all samples. A sample is a single update of data. 
	for (const auto& sample : samples)
	{
		const dds::sub::SampleInfo& info = sample.info();

		// Check to see whether the sample is valid
		// A sample can contain data (the sample is valid) or it can contain information about the instance’s lifecycle (the sample is not valid). 
		// “valid = true” indicates the update is a sample containing data; “valid = false” indicates the update is a sample containing an instance lifecycle update.
		if (info.valid() == true)  // New or updated
		{
			updated_data.push_back(sample.data());
		}
		else
		{
			// Since info contains invalid data, it may include metadata
			T sample_data;
			reader.key_value(sample_data, info.instance_handle());

			// To review the state data that is specific to instances, you use the sample.info().state().instance_state() method.
			// You can query this state to see if the instance is ALIVE, NOT_ALIVE_DISPOSED, or NOT_ALIVE_NO_WRITERS.
			dds::sub::status::InstanceState instance_state = info.state().instance_state();

			// Not alive, disposed: a DataWriter made an API call to notify all the DataReaders in the system that this instance has been “disposed.”
			if (instance_state == dds::sub::status::InstanceState::not_alive_disposed())
			{
				deleted_data.push_back(sample_data);
			}
		}
	}

	// EventAction is a callback
	std::map<int, EventAction> temp(m_callbacks_map);
	for (std::pair<int, EventAction> item : temp)
	{
		if (item.second != nullptr)
		{
            //concurrency::create_task([item, updated_data, deleted_data]() { return item.second(updated_data, deleted_data); });
			//return item.second(updated_data, deleted_data);
			m_event_thread = std::thread([item, updated_data, deleted_data]() { return item.second(updated_data, deleted_data); });
			m_event_thread.join();
		}
	}
}

template <class T>
int DDS::Comm::ReaderListener<T>::RegisterOnData(EventAction callback)
{
	m_mutex.lock();
	++m_last_ind;
	m_callbacks_map[m_last_ind] = callback;
	int ret_val = m_last_ind;
	m_mutex.unlock();

	return ret_val;
}

template <class T>
void DDS::Comm::ReaderListener<T>::UnregisterFromData(int ind)
{
	m_mutex.lock();
	m_callbacks_map.erase(ind);
	m_mutex.unlock();
}
