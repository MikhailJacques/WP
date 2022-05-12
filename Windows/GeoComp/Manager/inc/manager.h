// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	
// DESCRIPTION: This file declares TCP client that sends/receives messages to/from TCP server

#pragma once

#include <cmath>
#include <array>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <time.h>

#include "json.h"
#include "queue.h"
#include "logger.h"
#include "tcp_client.h"
#include "dds_comm.h"
#include "dds_msgs.hpp"
#include "reader_listener.h"
#include "config_tcp.h"
#include "state_machine.h"

using namespace std;
using namespace dds_msgs;

using namespace dds::core;
using namespace dds::domain;
using namespace dds::domain::qos;
using namespace dds::topic;
using namespace dds::pub;
using namespace DDS::Comm;

/// Manager class uses the StateMachine. 
/// Manager class design relies upon macros that greatly simplify usage by hiding the required source machinery.
/// 
/// Manager implements a landing-control state machine, where clients can induce state changes via an invocation of external events.
///
/// When the Manager class is created, its initial state is Initialization_State.
/// Once the initialization is complete it transfers to the Mission_Plan_State.
/// 
/// Creating a new state machine requires a few basic high-level steps:
/// 1. Inherit from the StateMachine base class
/// 2. Create a States enumeration with one entry per state function
/// 3. Create state functions using the STATE macros
/// 4. Optionally create Guard/Entry/Exit functions for each state using the GUARD, ENTRY and EXIT macros
/// 5. Create one state map lookup table using the STATE_MAP macros
/// 6. Create one transition map lookup table for each external event using the TRANSITION_MAP macros

/// @brief Manager utilizes StateMachine features including state machine inheritance, 
/// state function override, and Guard/Entry/Exit actions. 
class Manager : public StateMachine
{
public:

	explicit Manager(std::string sentinel);
	~Manager() {};
	void Start(void);

protected:

	void Stop(void);
	
private:

	void LogEvent(std::string sentinel);
	void LogPlatformLocation(std::string sentinel);

	// enum MissionType { None, AirBuild, AirDiff, GroundBuild, GroundDiff };

	/// Each state function must have an enumeration associated with it. 
	/// These enumerations are used to store the current state of the state machine.
	/// State enumeration order must match the order of state method entries in the state map.
	/// In Manager, States provides these enumerations, which are used later for indexing into the transition map and state map lookup tables.
	/// State enumeration order must match the order of state method entries in the state map.
	/// This way, a state enumeration is tied to a particular state function call. 
	/// EVENT_IGNORED and CANNOT_HAPPEN are two other constants used in conjunction with these state enumerations. 
	/// EVENT_IGNORED tells the state engine not to execute any state, just return and do nothing. 
	/// CANNOT_HAPPEN tells the state engine to fault. This abnormal catastrophic failure condition is never supposed to occur.
	enum States
	{
		INITIALIZATION_STATE,
		MISSION_PLAN_STATE,
		GET_DRONE_SCAN_ROUTE_STATE,
		DRONE_SCAN_ROUTE_STATE,
		START_JPEG_GENERATION_STATE,
		STOP_JPEG_GENERATION_STATE,
		MODEL_GENERATION_STATE,
		MODEL_UPLOAD_STATE,
		MODEL_REFERENCE_STATE,
		MISSION_END_STATE,
		FINALIZATION_STATE,
		NUM_OF_STATES
	};

	enum ModelType
	{
		NONE = 0,
		NEW_MODEL,
		DIFF_ANALYSIS
	};

	/// Define the state machine state functions with event data type
	/// The macro arguments are: the state machine class name (stateMachine), 
	/// state function name (stateName) and event data type (eventData)
	STATE_DECLARE(Manager, Initialization_State, NoEventData)
	STATE_DECLARE(Manager, Mission_Plan_State, NoEventData)
	STATE_DECLARE(Manager, Get_Drone_Scan_Route_State, NoEventData)
	STATE_DECLARE(Manager, Drone_Scan_Route_State, NoEventData)
	STATE_DECLARE(Manager, Start_Jpeg_Generation_State, NoEventData)
	STATE_DECLARE(Manager, Stop_Jpeg_Generation_State, NoEventData)
	STATE_DECLARE(Manager, Model_Generation_State, NoEventData)
	STATE_DECLARE(Manager, Model_Upload_State, NoEventData)
	STATE_DECLARE(Manager, Model_Reference_State, NoEventData)	
	STATE_DECLARE(Manager, Mission_End_State, NoEventData)
	STATE_DECLARE(Manager, Finalization_State, NoEventData)

	/// State map to define state object order. 
	/// Each state map entry defines a state object.
	BEGIN_STATE_MAP
		STATE_MAP_ENTRY(&Initialization_State)
		STATE_MAP_ENTRY(&Mission_Plan_State)
		STATE_MAP_ENTRY(&Get_Drone_Scan_Route_State)
		STATE_MAP_ENTRY(&Drone_Scan_Route_State)
		STATE_MAP_ENTRY(&Start_Jpeg_Generation_State)
		STATE_MAP_ENTRY(&Stop_Jpeg_Generation_State)
		STATE_MAP_ENTRY(&Model_Generation_State)
		STATE_MAP_ENTRY(&Model_Upload_State)
		STATE_MAP_ENTRY(&Model_Reference_State)
		STATE_MAP_ENTRY(&Mission_End_State)
		STATE_MAP_ENTRY(&Finalization_State)
	END_STATE_MAP

    // Geo Comp Manager receives MissionPlanMsg (1) (DDS) from Geo Comp Mission Broadcaster (COMMIT)
	// Arrival of MissionPlanMsg (1) triggers commencement of process execution, the execution of which 
	// cannot be interupted until either its completion indicated by the arrival of EndMissionMsg (15) or 
	// process abortion.
	// The decision which scenario to execute, whether it is an aerial build or an aerial difference or 
	// a ground build or a ground difference, is determined during runtime with the reception of the MissionPlanMsg 
	// where its MissionType parameter specifies the requested sequence.
	// Calculation of Mission Plan process can either be synchronous or asynchronous.
	// Regardless of the process calculation type there should be process status, i.e. started, completed.
	void MissionPlanMsgCb(std::vector<MissionPlanMsg> updated_data, std::vector<MissionPlanMsg> deleted_data);

    // Geo Comp Manager receives DroneScanRouteMsg (3) (DDS) from Geo Comp Flight Plan Service (Elta)
	void DroneScanRouteMsgCb(std::vector<DroneScanRouteMsg> updated_data, std::vector<DroneScanRouteMsg> deleted_data);

    // Geo Comp Manager receives PlatformLocationMsg (4) (DDS) from Geo Comp JPEG Generator (TES)
	void PlatformLocationMsgCb(std::vector<PlatformLocationMsg> updated_data, std::vector<PlatformLocationMsg> deleted_data);

    // Geo Comp Manager receives ReportJpegGenerationLivenessMsg (6) (DDS) from Geo Comp JPEG Generator (TES)
	void ReportJpegGenerationLivenessMsgCb(std::vector<ReportJpegGenerationLivenessMsg> updated_data, std::vector<ReportJpegGenerationLivenessMsg> deleted_data);

    // Geo Comp Manager receives EndMissionMsg (15) (DDS) from Geo Comp Mission Broadcaster (COMMIT)
	void EndMissionMsgCb(std::vector<BaseMsg> updated_data, std::vector<BaseMsg> deleted_data);

    // Geo Comp Manager receives UserInputMsg (?) (DDS) from UserInput Service (Elta)
	void UserInputMsgCb(std::vector<BaseMsg> updated_data, std::vector<BaseMsg> deleted_data);


    // Stores MissionPlanMsg (1) received from Geo Comp Mission Broadcaster (COMMIT)
	MissionPlanMsg m_mission_plan_msg;	

    // Stores GetDroneScanRouteMsg (2) sent to Geo Comp Flight Plan Service (Elta)
	GetDroneScanRouteMsg m_get_drone_scan_route_msg;
	
    // Stores DroneScanRouteMsg (3) received from Geo Comp Flight Plan Service (Elta)
    // Stores DroneScanRouteMsg (3) sent to Geo Comp Mission Broadcaster (COMMIT)
	DroneScanRouteMsg m_drone_scan_route_msg;			
		
	// The PlatformLocationMsg is cyclical in nature.
    // Stores PlatformLocationMsg (4) (DDS) received from Geo Comp JPEG Generator (TES)
    // Stores PlatformLocationMsg (4) sent to Geo Comp Telemetry Beacon (COMMIT)
	PlatformLocationMsg m_platform_location_msg;

    // Stores StartJpegGenerationMsg (5) sent to Geo Comp JPEG Generator (TES)
	StartJpegGenerationMsg m_start_jpeg_generation_msg;

    // Stores StopJpegGenerationMsg (51) sent to Geo Comp JPEG Generator (TES)
	BaseMsg m_stop_jpeg_generation_msg;
													
    // Stores ReportJpegGenerationLivenessMsg (6) received from Geo Comp JPEG Generator (TES)
	ReportJpegGenerationLivenessMsg m_report_jpeg_generation_liveness_msg;

    // Stores UploadCurrModelMsg (91) sent to Geo Comp LAS Service (COMMIT)
    // Stores UploadDiffModelMsg (92) sent to Geo Comp LAS Service (COMMIT)
	DoubleUrlMsg m_upload_model_to_cloud_msg;

    // Stores RequestRefModelMsg (14) sent to Geo Comp LAS Service (COMMIT)
	DoubleUrlMsg m_request_ref_model_msg;

    // Stores EndMissionMsg (15) received from Geo Comp Mission Broadcaster (COMMIT)
	BaseMsg m_mission_end_msg;	

    // Stores UserInputMsg (?) received from UserInput Service (Elta)
	BaseMsg m_user_input_msg;

    // true: object initialization succeded; false: otherwise
    bool m_constructor_success_flag;

	Queue<bool> m_start_jpeg_generation_queue;
	Queue<bool> m_model_generation_queue;
	Queue<bool> m_diff_analysis_queue;

	Queue<MissionPlanMsg> m_mission_plan_queue;
	Queue<DroneScanRouteMsg> m_drone_scan_route_queue;
	Queue<bool> m_mission_end_queue;

	// Rx counters
    unsigned int m_ui_cmd_cnt;
	unsigned int m_jpeg_generation_liveness_msg_cnt;
	
	// Tx counters
	unsigned int m_get_drone_scan_route_msg_cnt;
	unsigned int m_start_jpeg_generation_msg_cnt;
	unsigned int m_stop_jpeg_generation_msg_tx_cnt;
	unsigned int m_start_model_generation_msg_cnt;

	unsigned int m_upload_curr_model_to_cloud_msg_cnt;
	unsigned int m_upload_diff_model_to_cloud_msg_cnt;
	unsigned int m_request_ref_model_msg_cnt;

	DDS::Comm::Communicator m_dds_comm;
	DDS::Comm::Init_Params m_dds_comm_init_params;

	Logger m_event_logger;					// Logger object that writes event occurences to a text log file
	Logger m_platform_location_logger;		// Logger object that writes platform location coordinates to a text log file

	Queue<std::string> m_event_queue;		// Stores event messages for printing out in a dedicated thread
	Queue<std::string> m_platform_location_queue; // Stores platform location messages for printing out in a dedicated thread

	std::thread m_event_thread;				// Thread that logs event messages 
	std::thread m_platform_location_thread;	// Thread that logs platform location messages

	std::string m_sentinel;					// Sentinel value to terminate all operations

	TCP_Client m_tcp_client_sightec;		// TCP client for communicating with Geo Comp DSM App (Sightec) (TCP)

	unsigned short m_model_type;			// Model generation type: None, New Model, Differences Analysis

	// MJ TODO: Each state should ultimately have a unique predefined timeout for completing its intrinsic operations.
};