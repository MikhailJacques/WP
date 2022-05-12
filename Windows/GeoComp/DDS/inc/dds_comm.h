#pragma once

#include <mutex>
#include <future>
#include <functional>
#include <string>
#include <dds/dds.hpp>
#include <rti/core/ListenerBinder.hpp>
#include "reader_listener.h"

namespace DDS
{
    namespace Comm
    {
        struct Init_Params
        {
            int32_t domain_id = -1;                             // Set by the client
            std::string communicator_name = "";                 // Set by the client
            std::string qos_xml_uri = "USER_QOS_PROFILES.xml";      
            std::string qos_default_library_name = "";          // Set by the client
            std::string qos_default_profile_name = "";          // Set by the client
        };

        class Communicator
        {
            public:

                ~Communicator();
                bool Init(Init_Params init_params);
                bool IsInit() const;

                std::string GetName() const;

                template<class T>
                dds::pub::DataWriter<T> CreateWriter(const std::string& topic_name /*, const std::string &qos_library = "", const std::string &qos_profile = ""*/);

                template<class T>
                bool Write(const std::string& topic_name, T data);

                template<class T>
                void DisposeDataInstance(const std::string& topic_name, T data);

                template<class T>
                int RegisterOnData(const std::string& topic_name, std::function<void(std::vector<T> updated_data, std::vector<T> deleted_data)> callback);

                template<class T>
                bool UnregisterFromData(const std::string& topic_name, int user_ind);

            private:

                bool CreateParticipant();
                bool CreatePublisher();
                bool CreateSubscriber();

                template<class T>
                dds::sub::DataReader<T> CreateReader(const std::string& topic_name /*, const std::string &qos_library = "", const std::string &qos_profile = ""*/);

                template <class T>
                dds::topic::Topic<T> GetTopic(const std::string& name);

                std::string GetProfileId(const std::string& topic_name, const std::string& qos_library = "", const std::string& qos_profile = "");

                Init_Params m_init_params{};

                bool m_init_flag = false;
                dds::domain::qos::DomainParticipantQos m_participant_qos;
                dds::domain::DomainParticipant m_participant = nullptr;
                dds::pub::Publisher m_publisher = nullptr;
                dds::sub::Subscriber m_subscriber = nullptr;
                dds::core::QosProvider m_qos_provider = nullptr;
                std::mutex m_readers_mutex;
                std::mutex m_writers_mutex;
                std::mutex m_topics_mutex;

                // Collection of data readers. Each data reader is associated with a particular topic
                std::map<std::string, dds::sub::AnyDataReader> m_readers{};

                // Collection of data writers. Each data writer is associated with a particular topic
                std::map<std::string, dds::pub::AnyDataWriter> m_writers{};
        };
    }
}

template<class T>
bool DDS::Comm::Communicator::Write(const std::string& topic_name, T data)
{
    bool ret_val = false;

    if (IsInit() == false)
    {
        // TODO: log
        return false;
    }

    // Either get an existing writer or create a new writer for a particular topic
    try
    {
        dds::pub::DataWriter<T> writer = dds::core::null;
        m_writers_mutex.lock();

        std::map<std::string, dds::pub::AnyDataWriter>::iterator itr = m_writers.find(topic_name);

        if (itr == m_writers.end())
        {
            writer = CreateWriter<T>(topic_name);

            if (writer != dds::core::null)
            {
                // Add the newly created writer to 
                m_writers.insert(std::pair<std::string, dds::pub::AnyDataWriter>(topic_name, writer));
            }
        }
        else
        {
            writer = itr->second.get<T>();
        }

        m_writers_mutex.unlock();

        if (writer != dds::core::null)
        {
            writer.write(data);
            ret_val = true;
        }
    }
    catch (std::exception& e)
    {
        e.what();
        ret_val = false;
    }

    return ret_val;
}

template <class T>
void DDS::Comm::Communicator::DisposeDataInstance(const std::string& topic_name, T data)
{
    if (IsInit() == false)
        return;

    m_writers_mutex.lock();

    // Attempt to retrieve a writer for a particular topic
    std::map<std::string, dds::pub::AnyDataWriter>::iterator itr = m_writers.find(topic_name);

    if (itr != m_writers.end())
    {
        auto writer = itr->second.get<T>();
        dds::core::InstanceHandle handler = writer.lookup_instance(data);

        if (false == handler.is_nil())
        {
            writer.dispose_instance(handler);
        }
    }

    m_writers_mutex.unlock();
}

template<class T>
int DDS::Comm::Communicator::RegisterOnData(const std::string& topic_name, std::function<void(std::vector<T> updated_data, std::vector<T> deleted_data)> callback)
{
    int ret_val = -1;

    dds::sub::DataReader<T> reader = dds::core::null;

    if (IsInit() == false)
    {
        return -2;
    }

    m_readers_mutex.lock();

    // Attempt to retrieve a writer for a particular topic
    std::map<std::string, dds::sub::AnyDataReader>::iterator itr = m_readers.find(topic_name);

    // Either create a new reader or retrieve an existing reader for a particular topic
    if (itr == m_readers.end())
    {
        reader = CreateReader<T>(topic_name);

        if (reader != dds::core::null)
        {
            m_readers.insert(std::pair<std::string, dds::sub::AnyDataReader>(topic_name, reader));
        }
    }
    else
    {
        reader = itr->second.get<T>();
    }

    m_readers_mutex.unlock();

    if (reader != dds::core::null)
    {
        dds::sub::DataReaderListener<T>* base_listener = reader.listener();

        if (base_listener != dds::core::null)
        {
            ReaderListener<T>* listener = dynamic_cast<ReaderListener<T>*>(base_listener);

            if (listener != dds::core::null)
            {
                ret_val = listener->RegisterOnData(callback);
            }
        }
    }

    return ret_val;
}

template<class T>
bool DDS::Comm::Communicator::UnregisterFromData(const std::string& topic_name, int user_ind)
{
    bool ret_val = false;
    dds::sub::DataReader<T> reader = dds::core::null;

    if (IsInit() == false)
    {
        return false;
    }

    std::map<std::string, dds::sub::AnyDataReader>::iterator itr = m_readers.find(topic_name);

    if (itr != m_readers.end())
    {
        reader = itr->second.get<T>();

        if (reader != dds::core::null)
        {
            dds::sub::DataReaderListener<T>* base_listener = reader.listener();

            if (base_listener != dds::core::null)
            {
                ReaderListener<T>* listener = dynamic_cast<ReaderListener<T>*>(base_listener);

                if (listener != dds::core::null)
                {
                    listener->UnregisterFromData(user_ind);
                    ret_val = true;
                }
            }
        }
    }

    return ret_val;
}

template <class T>
dds::topic::Topic<T> DDS::Comm::Communicator::GetTopic(const std::string& name)
{
    dds::topic::Topic<T> topic = dds::core::null;

    try
    {
        m_topics_mutex.lock();
        topic = dds::topic::find<dds::topic::Topic<T>>(m_participant, name);

        if (topic == dds::core::null)
        {
            topic = dds::topic::Topic<T>(m_participant, name);
        }

        m_topics_mutex.unlock();
    }
    catch (std::exception& e)
    {
        // TODO: log;
        e.what();
    }

    return topic;
}

template<class T>
dds::pub::DataWriter<T> DDS::Comm::Communicator::CreateWriter(const std::string& topic_name /*, const std::string &qos_library, const std::string &qos_profile*/)
{
    dds::pub::DataWriter<T> writer = dds::core::null;

    try
    {
        dds::topic::Topic<T> topic = GetTopic<T>(topic_name);
        std::string profile_id = GetProfileId(topic_name/*, qos_library, qos_profile*/);
        writer = dds::pub::DataWriter<T>(m_publisher, topic, m_qos_provider.datawriter_qos(profile_id));

        if (writer != dds::core::null)
        {
            m_writers.insert(std::pair<std::string, dds::pub::AnyDataWriter>(topic_name, writer));
        }
    }
    catch (std::exception& e)
    {
        // TODO: log;
        e.what();
    }

    return writer;
}

template<class T>
dds::sub::DataReader<T> DDS::Comm::Communicator::CreateReader(const std::string& topic_name /*, const std::string &qos_library, const std::string &qos_profile*/)
{
    dds::sub::DataReader<T> reader = dds::core::null;

    try
    {
        dds::topic::Topic<T> topic = GetTopic<T>(topic_name);
        std::string profile_id = GetProfileId(topic_name/*, qos_library, qos_profile*/);
        reader = dds::sub::DataReader<T>(m_subscriber, topic, m_qos_provider.datareader_qos(profile_id), new ReaderListener<T>);

        // reader.retain();
    }
    catch (std::exception& e)
    {
        // TODO: log;
        e.what();
    }

    return reader;
}