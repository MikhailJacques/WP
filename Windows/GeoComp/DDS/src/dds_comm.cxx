#include <utility>
#include "dds_comm.h"
#include "monitor/monitor_common.h"

using namespace dds::domain;
using namespace dds::pub;
using namespace dds::sub;
using namespace dds::core;
using namespace dds::core::policy;
using rti::core::policy::Property;
using namespace DDS::Comm;

Communicator::~Communicator()
{
	for (auto reader : m_readers)
	{
		reader.second.close();
	}

	for (auto writer : m_writers)
	{
		writer.second.close();
	}
}

bool Communicator::Init(Init_Params init_params)
{
	if (m_init_flag == true)
	{
		// TODO: LOG
		return false;
	}

	try
	{
		m_init_params = std::move(init_params);

		if (m_init_params.qos_xml_uri.empty() == false)
		{
			m_qos_provider = QosProvider(m_init_params.qos_xml_uri);
		}
		else
		{
            // Look for USER_QOS_PROFILES.xml
            m_qos_provider = QosProvider::Default();
		}

		if (CreateParticipant() == false)
		{
			// TODO: LOG
		}

		else if (CreatePublisher() == false)
		{
			// TODO: LOG
		}
				
		else if (CreateSubscriber() == false)
		{
			// TODO: LOG
		}
		else
		{
			m_init_flag = true;
		}
	}
	catch (std::exception& e)
	{
		// TODO: LOG
        e.what();
	}

	return m_init_flag;
}

bool Communicator::IsInit() const
{
	return m_init_flag;
}

std::string Communicator::GetName() const
{
    return m_init_params.communicator_name;
}

bool Communicator::CreateParticipant()
{
    bool ret_val = true;

    if (m_init_params.domain_id < 0)
    {
        return false;
    }

    try
    {
        if (m_init_params.qos_default_profile_name.empty())
        {
            // Default QoS profile
            m_participant_qos = m_qos_provider.participant_qos();
        }
        else
        {
            // Developer-defined QoS profile
            m_participant_qos = m_qos_provider.participant_qos(m_init_params.qos_default_library_name + "::" + m_init_params.qos_default_profile_name);
        }

        // Create a DomainParticipant with Qos
        m_participant = DomainParticipant(m_init_params.domain_id, m_participant_qos);  
    }
    catch (std::exception& e)
    {
        e.what();
        ret_val = false;
    }

    return ret_val;
}

bool Communicator::CreatePublisher()
{
    bool ret_val = true;

    try
    {
        if (m_init_params.qos_default_profile_name.empty())
        {
            // Default profile
            m_publisher = Publisher(m_participant, m_qos_provider.publisher_qos());
        }
        else
        {
            m_publisher = Publisher(m_participant, m_qos_provider.publisher_qos(m_init_params.qos_default_library_name + "::" + m_init_params.qos_default_profile_name));
        }

        // Set partitions
        // SetPartitionsPublisher(m_init_params.partitions_publisher);
    }
    catch (std::exception& e)
    {
        e.what();
        ret_val = false;
    }

    return ret_val;
}

bool Communicator::CreateSubscriber()
{
    bool ret_val = true;

    try
    {
        if (m_init_params.qos_default_profile_name.empty())
        {
            // Default profile
            m_subscriber = Subscriber(m_participant, m_qos_provider.subscriber_qos());
        }
        else
        {
            m_subscriber = Subscriber(m_participant, m_qos_provider.subscriber_qos(m_init_params.qos_default_library_name + "::" + m_init_params.qos_default_profile_name));
        }

        // Set partitions
        // SetPartitionsSubscriber(m_init_params.partitions_subscriber);
    }
    catch (std::exception& e)
    {
        e.what();
        ret_val = false;
    }

    return ret_val;
}

//void Communicator::SetPartitionsPublisher(const std::vector<std::string>& partition_names)
//{
//    if (partition_names.empty() == false)
//    {
//    	auto partition = m_qos_provider.publisher_qos().policy<Partition>();
//    	partition.name(partition_names);
//    	m_publisher.qos(m_qos_provider.publisher_qos() << partition);
//    }
//}

//void Communicator::SetPartitionsSubscriber(const std::vector<std::string>& partition_names)
//{
//    if (partition_names.empty() == false)
//    {
//    	auto partition = m_qos_provider.subscriber_qos().policy<Partition>();
//    	partition.name(partition_names);
//    	m_subscriber.qos(m_qos_provider.subscriber_qos() << partition);
//    }
//}

std::string Communicator::GetProfileId(const std::string &topic_name, const std::string &qos_library, const std::string &qos_profile)
{
	std::string library_id = !qos_library.empty() ? (qos_library) : (!m_init_params.qos_default_library_name.empty() ? m_init_params.qos_default_library_name : m_qos_provider->default_library().get());
	
	std::string profile_id = qos_profile.empty() ? topic_name : qos_profile;
	
	return library_id + "::" + profile_id;
}