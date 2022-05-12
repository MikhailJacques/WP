// AUTHOR:		Mikhail Jacques
// PROJECT:		WorldPerception
// DOCUMENT:	
// DESCRIPTION: This file declares a state machine where clients can induce changes via invocation of external events

#pragma once

#include <cmath>
#include <array>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

#include "json.h"
#include "queue.h"
#include "logger.h"
#include "dds_comm.h"
#include "dds_msgs.hpp"
#include "reader_listener.h"
#include "state_machine.h"

using namespace std;
using namespace dds_msgs;

using namespace dds::core;
using namespace dds::domain;
using namespace dds::domain::qos;
using namespace dds::topic;
using namespace dds::pub;
using namespace DDS::Comm;

/// FlightPlan class uses the StateMachine. 
/// FlightPlan class design relies upon macros that greatly simplify usage by hiding the required source machinery.
/// 
/// FlightPlan implements a landing-control state machine, where clients can induce state changes via an invocation of external events.
///
/// When the FlightPlan class is created, its initial state is Initialization_State.
/// Once the initialization is complete it transfers to the Mission_Plan_State.
/// 
/// Creating a new state machine requires a few basic high-level steps:
/// 1. Inherit from the StateMachine base class
/// 2. Create a States enumeration with one entry per state function
/// 3. Create state functions using the STATE macros
/// 4. Optionally create Guard/Entry/Exit functions for each state using the GUARD, ENTRY and EXIT macros
/// 5. Create one state map lookup table using the STATE_MAP macros
/// 6. Create one transition map lookup table for each external event using the TRANSITION_MAP macros

class CounterData : public EventData
{
public:
	unsigned short ui_cmd_cnt;
};

/// @brief FlightPlan utilizes StateMachine features including state machine inheritance, 
/// state function override, and Guard/Entry/Exit actions. 
class FlightPlan : public StateMachine
{
public:

    FlightPlan(void);
	~FlightPlan() {};
	void Start(void);

protected:

	void Stop(CounterData *data);

private:

	/// Each state function must have an enumeration associated with it. 
	/// These enumerations are used to store the current state of the state machine.
	/// State enumeration order must match the order of state method entries in the state map.
	/// In FlightPlan, States provides these enumerations, which are used later for indexing into the transition map and state map lookup tables.
	/// State enumeration order must match the order of state method entries in the state map.
	/// This way, a state enumeration is tied to a particular state function call. 
	/// EVENT_IGNORED and CANNOT_HAPPEN are two other constants used in conjunction with these state enumerations. 
	/// EVENT_IGNORED tells the state engine not to execute any state, just return and do nothing. 
	/// CANNOT_HAPPEN tells the state engine to fault. This abnormal catastrophic failure condition is never supposed to occur.
	enum States
	{
		INITIALIZATION_STATE,
		GET_DRONE_SCAN_ROUTE_STATE,
		CALCULATE_DRONE_SCAN_ROUTE_STATE,
		SEND_DRONE_SCAN_ROUTE_STATE,
		FINALIZATION_STATE,
		NUM_OF_STATES
	};

	/// Define the state machine state functions with event data type
	/// The macro arguments are: the state machine class name (stateMachine), 
	/// state function name (stateName) and event data type (eventData)
	STATE_DECLARE(FlightPlan, Initialization_State, NoEventData)
	STATE_DECLARE(FlightPlan, Get_Drone_Scan_Route_State, NoEventData)
	STATE_DECLARE(FlightPlan, Calculate_Drone_Scan_Route_State, NoEventData)
	STATE_DECLARE(FlightPlan, Send_Drone_Scan_Route_State, NoEventData)
	STATE_DECLARE(FlightPlan, Finalization_State, CounterData)

	/// State map to define state object order. 
	/// Each state map entry defines a state object.
	BEGIN_STATE_MAP
		STATE_MAP_ENTRY(&Initialization_State)
		STATE_MAP_ENTRY(&Get_Drone_Scan_Route_State)
		STATE_MAP_ENTRY(&Calculate_Drone_Scan_Route_State)
		STATE_MAP_ENTRY(&Send_Drone_Scan_Route_State)
		STATE_MAP_ENTRY(&Finalization_State)
	END_STATE_MAP

    // Geo Comp Flight Plan Service receives GetDroneScanRouteMsg (2) (DDS) from Geo Comp Manager (Elta)
	void GetDroneScanRouteMsgCb(std::vector<GetDroneScanRouteMsg> updated_data, std::vector<GetDroneScanRouteMsg> deleted_data);

    // Flight Plan Service receives UserInputMsg (?) (DDS) from UserInput Service (Elta)
	void UserInputMsgCb(std::vector<BaseMsg> updated_data, std::vector<BaseMsg> deleted_data);
	
    GetDroneScanRouteMsg m_get_drone_scan_route_msg;	// Stores GetDroneScanRouteMsg (2) received from Geo Comp Manager (Elta)
    DroneScanRouteMsg m_drone_scan_route_msg;			// Stores DroneScanRouteMsg (3) sent to Geo Comp Manager (Elta)
    BaseMsg m_user_input_msg;							// Stores UserInputMsg (?) received from UserInput Service (Elta)
													
	bool m_constructor_success_flag;					// true: object initialization succeded; false: otherwise
	unsigned int m_drone_scan_route_msg_cnt;
	Queue<bool> m_get_drone_scan_route_queue;
	
	DDS::Comm::Communicator m_dds_comm;
	DDS::Comm::Init_Params m_dds_comm_init_params;

	Logger m_event_logger;								// Logger object that writes textual information to a text log file
};