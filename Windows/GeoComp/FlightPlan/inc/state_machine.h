// AUTHOR:		https://www.codeproject.com/Articles/1087619/State-Machine-Design-in-Cplusplus-2
// PROJECT:		WorldPerception
// DOCUMENT:	None
// DESCRIPTION: This file declares state machine

#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H

//#include <stdio.h>
#include <typeinfo>
#include "fault.h"

/// ----- Motivation -----
/// Implementing a state machine using this method as opposed to the old switch statement style may seem like extra effort. 
/// However, the payoff is in a more robust design that is capable of being employed uniformly over an entire multithreaded system. 
/// Having each state in its own function provides easier reading than a single huge switch statement, and allows unique event data to be sent to each state. 
/// In addition, validating state transitions prevents client misuse by eliminating the side effects caused by unwanted state transitions.

/// ----- Internal and External Events -----
/// An event is the stimulus that causes a state machine to transition between states.
/// Events can be broken out into two categories : external and internal.
/// The external event, at its most basic level, is a function call into a state-machine object.
/// These functions are public and are called from the outside or from code external to the state-machine object.
/// Any thread or task within a system can generate an external event. 
/// If the external event function call causes a state transition to occur, the state will execute synchronously within the caller's thread of control. 
/// An internal event, on the other hand, is self-generated by the state machine itself during state execution.
///
/// A typical scenario consists of an external event being generated, which, again, boils down to a function call into the class's public interface. 
/// Based upon the event being generated and the state machine's current state, a lookup is performed to determine if a transition is required.
/// If so, the state machine transitions to the new state and the code for that state executes.
/// At the end of the state function, a check is performed to determine whether an internal event has been generated.
/// If so, another transition is performed and the new state gets a chance to execute.
/// This process continues until the state machine is no longer generating internal events, at which time the original external event function call returns.
/// The external event and all internal events, if any, execute within the caller's thread of control.
///
/// Once the external event starts the state machine executing, it cannot be interrupted by another external event 
/// until the external event and all internal events have completed execution if locks are used. 
/// This run to completion model provides a multithread-safe environment for the state transitions.
/// Semaphores or mutexes can be used in the state machine engine to block other threads that might be trying to simultaneously access the same object.
/// See source code function ExternalEvent() comments for where the locks go.

/// ----- Event Data -----
/// When an event is generated, it can optionally attach event data to be used by the state function during execution.
/// Once the state has completed execution, the event data is considered used up and must be deleted.
/// Therefore, any event data sent to a state machine must be created on the heap, via operator new, so that the state machine can delete it once used.
/// In addition, in this particular implementation the event data must inherit from the EventData base class.
/// This gives the state machine engine a common base class for which to delete all event data.
/// 
/// The state machine implementation now has a build option that removes the requirement to create external event data on the heap.
/// If EXTERNAL_EVENT_NO_HEAP_DATA is defined it changes how a client sends data to the state machine. 
/// When undefined, the ExternalEvent() pData argument must be created on the heap. 
/// The state machine will automatically delete the EventData pointer during state execution. 
/// When defined, clients must not heap allocate EventData with operator new. 
/// InternalEvent() used inside the state machine always heap allocates event data. 
// #define EXTERNAL_EVENT_NO_HEAP_DATA 1

/// Use the xallocator instead of the global heap. See xallocator.h for more info. 
/// Any EventData, or derived class thereof, created with new/delete will be routed to the xallocator. 
//#include "xallocator.h"

/// ----- State Transitions -----
/// When an external event is generated, a lookup is performed to determine the state transition course of action.
/// There are three possible outcomes to an event: new state, event ignored, or cannot happen.
/// A new state causes a transition to a new state where it is allowed to execute.
/// Transitions to the existing state are also possible, which means the current state is re-executed.
/// For an ignored event, no state executes. However, the event data, if any, is deleted. 
/// The last possibility, cannot happen, is reserved for situations where the event is invalid given the current state of the state machine. 
/// If this occurs, the software faults.
/// In this implementation, internal events are not required to perform a validating transition lookup. The state transition is assumed to be valid. 
/// While we could check for both valid internal and external event transitions, in practice, 
/// this just takes more storage space and generates busywork for very little benefit.
/// The real need for validating transitions lies in the asynchronous, external events where a client can cause an event to occur at an inappropriate time.
/// Once the state machine is executing, it cannot be interrupted. It is under the control of the class's private implementation, 
/// thereby making transition checks unnecessary. 
/// This gives the designer the freedom to change states, via internal events, without the burden of updating transition tables.

/// @beief Unique state machine event data must inherit from this class.
class EventData
{
	public:
		virtual ~EventData() {}
	
		/// Since on some systems, using the heap is undesirable this single macro.
		/// provides fixed block memory allocations for all EventData and derived classes.
		/// It is optional, but when used it creates memory blocks from static memory or previously recycled heap memory. 
		// XALLOCATOR
};

typedef EventData NoEventData;

class StateMachine;

/// @brief Abstract state base class that all states inherit from.
class StateBase
{
	public:
		/// Called by the state machine engine to execute a state action. 
		/// If a guard condition exists and it evaluates to false, the state action will not execute. 
		/// @param[in] sm - A state machine instance.
		/// @param[in] data - The event data. 
		virtual void InvokeStateAction(StateMachine* sm, const EventData* data) const = 0;
};

// The StateAction derives from StateBase and its sole responsibility is to implement InvokeStateAction() and 
/// cast the StateMachine and EventData pointers to the correct derived class types, then call the state member function. 
/// Therefore, the state engine overhead to call each state function is one virtual function call, one static_cast<> and one dynamic_cast<>.
/// @brief StateAction takes three template arguments: 
/// - A state machine class,
/// - A state function event data type (derived from EventData),
/// - A state machine member function pointer.  
template <class SM, class Data, void (SM::*Func)(const Data*)>
class StateAction : public StateBase
{
	public:

		/// @see StateBase::InvokeStateAction
		virtual void InvokeStateAction(StateMachine* sm, const EventData* data) const 
		{
			/// Downcast the state machine and event data to the correct derived type
			SM* derived_sm_ptr = static_cast<SM*>(sm);
		
			/// If this check fails, there is a mismatch between the STATE_DECLARE event data type and the data type being sent to the state function. 
			/// For instance, given the following state defintion:					STATE_DECLARE(MyStateMachine, MyStateFunction, MyEventData)
			/// The following internal event transition is valid:					InternalEvent(STATE_MY_STATE_FUNCTION, new MyEventData());
			/// This next internal event is invalid and causes the assert to fail:	InternalEvent(STATE_MY_STATE_FUNCTION, new OtherEventData());
			const Data* derived_data_ptr = dynamic_cast<const Data*>(data);
			ASSERT_TRUE(derived_data_ptr != NULL);

			/// Call the state function
			(derived_sm_ptr->*Func)(derived_data_ptr);
	}
};

/// The template arguments to StateAction<> are a state machine class (SM), an event data type (Data) and a member function pointer to the state function (Func).
/// GuardCondition<>, EntryAction<> and ExitAction<> classes also exist and their role is the same � 
/// typecast state machine and event data then call the action member function.
/// Minor variations exist with the template arguments.
/// The GuardCondition<> class Func template parameter changes slightly and returns a bool. 
/// ExitAction<> doesn't have a Data template argument.

/// @brief Abstract guard base class that all guards classes inherit from.
class GuardBase
{
	public:
		/// Called by the state machine engine to execute a guard condition action. 
		/// If guard condition evaluates to true the state action is executed. If false, no state transition is performed.
		/// @param[in] sm - A state machine instance. 
		/// @param[in] data - The event data. 
		/// @return Returns true if no guard condition or the guard condition evaluates to true.
		virtual bool InvokeGuardCondition(StateMachine* sm, const EventData* data) const = 0;
};

/// @brief GuardCondition takes three template arguments: 
/// - A state machine class,
///  -A state function event data type (derived from EventData)
/// - A state machine member function pointer. 
template <class SM, class Data, bool (SM::*Func)(const Data*)>
class GuardCondition : public GuardBase
{
	public:

		virtual bool InvokeGuardCondition(StateMachine* sm, const EventData* data) const 
		{
			SM* derived_sm_ptr = static_cast<SM*>(sm);		
			const Data* derived_data_ptr = dynamic_cast<const Data*>(data);
			ASSERT_TRUE(derived_data_ptr != NULL);

			/// Call the guard function
			return (derived_sm_ptr->*Func)(derived_data_ptr);
		}
};

/// @brief Abstract entry base class that all entry classes inherit from.
class EntryBase
{
	public:
		/// Called by the state machine engine to execute a state entry action. 
		/// Called when entering a state. 
		/// @param[in] sm - A state machine instance. 
		/// @param[in] data - The event data.
		virtual void InvokeEntryAction(StateMachine* sm, const EventData* data) const = 0;
};

/// @brief EntryAction takes three template arguments: 
/// - A state machine class,
/// - A state function event data type (derived from EventData),
/// - A state machine member function pointer.  
template <class SM, class Data, void (SM::*Func)(const Data*)>
class EntryAction : public EntryBase
{
	public:
		virtual void InvokeEntryAction(StateMachine* sm, const EventData* data) const
		{
			SM* derived_sm_ptr = static_cast<SM*>(sm);
			const Data* derived_data_ptr = dynamic_cast<const Data*>(data);
			ASSERT_TRUE(derived_data_ptr != NULL);

			/// Call the entry function
			(derived_sm_ptr->*Func)(derived_data_ptr);
		}
};

/// @brief Abstract exit base class that all exit classes inherit from.
class ExitBase
{
	public:
		/// Called by the state machine engine to execute a state exit action. Called when leaving a state. 
		/// @param[in] sm - A state machine instance. 
		virtual void InvokeExitAction(StateMachine* sm) const = 0;
};

/// @brief ExitAction takes two template arguments: 
/// A state machine class,
/// A state machine member function pointer.   
template <class SM, void (SM::*Func)(void)>
class ExitAction : public ExitBase
{
	public:
		virtual void InvokeExitAction(StateMachine* sm) const
		{
			SM* derived_sm_ptr = static_cast<SM*>(sm);

			/// Call the exit function
			(derived_sm_ptr->*Func)();
		}
};

/// @brief A structure to hold a single row within the state map. 
struct StateMapRow
{
	const StateBase* const State;
};

/// @brief A structure to hold a single row within the extended state map. 
struct StateMapRowEx
{
	const StateBase* const State;
	const GuardBase* const Guard;
	const EntryBase* const Entry;
	const ExitBase* const Exit;
};

/// StateMachine Class declaration
/// Two base classes are necessary when creating a state machine: StateMachine and EventData.
/// A class inherits from StateMachine to obtain the necessary mechanisms to support state transitions and event handling.
/// The StateMachine header also contains various preprocessor multiline macros to ease implementation of the state machine. 
/// To send unique data to the state functions, the structure must inherit from the EventData base class.

/// @brief StateMachine implements a software-based state machine. 
class StateMachine 
{
	public:

		enum { EVENT_IGNORED = 0xFE, CANNOT_HAPPEN };

		///	Constructor.
		///	@param[in] maxStates - the maximum number of state machine states.
		StateMachine(unsigned char maxStates, unsigned char initialState = 0);

		virtual ~StateMachine() {}

		/// Gets the current state machine state.
		/// @return Current state machine state.
		unsigned char GetCurrentState() { return m_currentState; }

		/// Gets the maximum number of state machine states.
		/// @return The maximum state machine states. 
		unsigned char GetMaxStates() { return MAX_STATES; }
	
	protected:

		/// External state machine event.
		/// Generates an external event to the state machine using as arguments the new state and a pointer to an EventData object, if any. 
		/// @param[in] newState - the state machine state to transition to.
		/// @param[in] pData - the event data sent to the state.
		void ExternalEvent(unsigned char newState, const EventData* pData = NULL);

		/// Internal state machine event. 
		/// Generates an internal event to the state machine using as arguments the new state and a pointer to an EventData object, if any. 
		/// These events are generated while executing within a state machine state.
		/// @param[in] newState - the state machine state to transition to.
		/// @param[in] pData - the event data sent to the state.
		void InternalEvent(unsigned char newState, const EventData* pData = NULL);
	
	private:

		/// The maximum number of state machine states.
		const unsigned char MAX_STATES;

		/// The current state machine state.
		unsigned char m_currentState;

		/// The new state the state machine has yet to transition to. 
		unsigned char m_newState;

		/// Set to true when an event is generated.
		bool m_eventGenerated;

		/// The state event data pointer.
		const EventData* m_pEventData;

		/// The GetStateMap() and GetStateMapEx() functions return an array of StateMapRow or StateMapRowEx 
		/// instances which will be retrieved by the state engine when appropriate. 
		/// The inheriting class must return an array with one of these functions. 
		/// If the state machine only has state functions, GetStateMap() is used. 
		/// If guard/entry/exit features are required, the GetStateMapEx() is used. 
		/// The other unused version must return NULL. 
		/// M+ultiline macros are provided to implement these functions for us.

		/// Gets the state map as defined in the derived class. 
		/// The BEGIN_STATE_MAP, STATE_MAP_ENTRY and END_STATE_MAP macros are used to assist in creating the map. 
		/// A state machine only needs to return a state map using either GetStateMap() or GetStateMapEx(), but not both. 
		/// @return An array of StateMapRow pointers with the array size MAX_STATES or NULL if the state machine uses the GetStateMapEx(). 
		virtual const StateMapRow* GetStateMap() = 0;

		/// Gets the extended state map as defined in the derived class. 
		/// The BEGIN_STATE_MAP_EX, STATE_MAP_ENTRY_EX, STATE_MAP_ENTRY_ALL_EX, and END_STATE_MAP_EX macros are used to assist in creating the map. 
		/// A state machine only needs to return a state map using either GetStateMap() or GetStateMapEx() but not both. 
		/// @return An array of StateMapRowEx pointers with the array size MAX_STATES or NULL if the state machine uses the GetStateMap().
		virtual const StateMapRowEx* GetStateMapEx() = 0;

		/// Set a new current state.
		/// @param[in] newState - the new state.
		void SetCurrentState(unsigned char newState) { m_currentState = newState; }

		/// State machine engine that executes the external event and, optionally, all 
		/// internal events generated during state execution.
		void StateEngine(void); 	
		void StateEngine(const StateMapRow* const pStateMap);
		void StateEngine(const StateMapRowEx* const pStateMapEx);
};

/// Notice the multiline macros prepend "State_" to each state function name. 
/// Additional characters are added to each state/guard/entry/exit function automatically within the macro. 
/// For instance, if declaring a function using STATE_DEFINE(Worker, Finalization_State, NoEventData) the actual state function is called State_Stopped().
/// State_ - state function prepend characters
/// Guard_ - guard function prepend characters
/// Entry_ - entry function prepend characters
/// Exit_ - exit function prepend characters
/// After a state function is declared, define a state function implementation with the STATE_DEFINE macro.
/// The arguments are the state machine class name, state function name, and event data type.
/// The code to implement a state behavior goes inside the state function.
/// Note, any state function code may call InternalEvent() to switch to another state.
/// Guard / Entry / Exit functions cannot call InternalEvent(), otherwise a runtime error will result.

#define STATE_DECLARE(stateMachine, stateName, eventData) \
	void State_##stateName(const eventData*); \
	StateAction<stateMachine, eventData, &stateMachine::State_##stateName> stateName;
	
#define STATE_DEFINE(stateMachine, stateName, eventData) \
	void stateMachine::State_##stateName(const eventData* data)
		
#define GUARD_DECLARE(stateMachine, guardName, eventData) \
	bool Guard_##guardName(const eventData*); \
	GuardCondition<stateMachine, eventData, &stateMachine::Guard_##guardName> guardName;
	
/// The guard condition function returns true if the state function is to be executed or false otherwise.
#define GUARD_DEFINE(stateMachine, guardName, eventData) \
	bool stateMachine::Guard_##guardName(const eventData* data)

#define ENTRY_DECLARE(stateMachine, entryName, eventData) \
	void Entry_##entryName(const eventData*); \
	EntryAction<stateMachine, eventData, &stateMachine::Entry_##entryName> entryName;
	
#define ENTRY_DEFINE(stateMachine, entryName, eventData) \
	void stateMachine::Entry_##entryName(const eventData* data)

#define EXIT_DECLARE(stateMachine, exitName) \
	void Exit_##exitName(void); \
	ExitAction<stateMachine, &stateMachine::Exit_##exitName> exitName;
	
#define EXIT_DEFINE(stateMachine, exitName) \
	void stateMachine::Exit_##exitName(void)

/// A transition map allows the state machine to know what transitions should occur.
/// A transition map is a lookup table that maps the m_currentState variable to a state enum constant.
/// Every external event has a transition map table created with three macros: BEGIN_TRANSITION_MAP, TRANSITION_MAP_ENTRY, END_TRANSITION_MAP

/// BEGIN_TRANSITION_MAP starts the map. 
/// Each TRANSITION_MAP_ENTRY that follows indicates what the state machine should do based upon the current state.
/// The number of entries in each transition map table must match the number of state functions exactly.
/// The location of each entry matches the order of state functions defined within the state map.
#define BEGIN_TRANSITION_MAP \
    static const unsigned char TRANSITIONS[] = {\

/// Each entry within the transition map is a StateMapRow:
#define TRANSITION_MAP_ENTRY(entry)\
    entry,

/// END_TRANSITION_MAP terminates the map. 
/// The argument to this end macro is the event data, if any. 
#define END_TRANSITION_MAP(data) \
    };\
	ASSERT_TRUE(GetCurrentState() < NUM_OF_STATES); \
    ExternalEvent(TRANSITIONS[GetCurrentState()], data); \
	C_ASSERT((sizeof(TRANSITIONS)/sizeof(unsigned char)) == NUM_OF_STATES); 

/// GetCurrentState() returns the state machine current state. NUM_OF_STATES is the maximum parent class State enum value. 
/// GetMaxStates() returns the maximum state value for the entire state machine up to the most-derived class. 
/// The expanded code shows that if the current state is higher than the maximum parent class state value (i.e., SelfTest::NUM_OF_STATES),
/// but less than the entire state machine maximum state value (i.e., CentrifugeTest::NUM_OF_STATES), then transition to state Failed. 
/// In this way, transitions are uniformly handled if outside the range handled by the parent partial transition map. 
/// Otherwise, the partial transition map handles the state transition. 
/// EVENT_IGNORED and CANNOT_HAPPEN are also valid PARENT_TRANSITION arguments.
#define PARENT_TRANSITION(state) \
	if (GetCurrentState() >= NUM_OF_STATES && \
		GetCurrentState() < GetMaxStates()) { \
		ExternalEvent(state); \
		return; }

/// The state-machine engine knows which state function to call by using the state map. 
/// The state map maps the m_currentState variable to a specific state function. 
/// For instance, if m_currentState is 2, then the third state-map function pointer entry will be called (counting from zero). 
/// The state map table is created using these three macros: BEGIN_STATE_MAP, STATE_MAP_ENTRY, END_STATE_MAP

#define BEGIN_STATE_MAP \
	private:\
	virtual const StateMapRowEx* GetStateMapEx() { return NULL; }\
	virtual const StateMapRow* GetStateMap() {\
		static const StateMapRow STATE_MAP[] = { 

#define STATE_MAP_ENTRY(stateName)\
	stateName,

#define END_STATE_MAP \
    }; \
	C_ASSERT((sizeof(STATE_MAP)/sizeof(StateMapRow)) == NUM_OF_STATES); \
	return &STATE_MAP[0]; }

#define BEGIN_STATE_MAP_EX \
	private:\
	virtual const StateMapRow* GetStateMap() { return NULL; }\
	virtual const StateMapRowEx* GetStateMapEx() {\
		static const StateMapRowEx STATE_MAP[] = { 

#define STATE_MAP_ENTRY_EX(stateName)\
	{ stateName, 0, 0, 0 },


/// The STATE_MAP_ENTRY_ALL_EX macro has four arguments for the state action, guard condition, entry action and exit action in that order. 
/// The state action is mandatory, but the other actions are optional. 
/// If a state doesn't have an action, then use 0 for the argument. 
/// If a state doesn't have any Guard/Entry/Exit options, the STATE_MAP_ENTRY_EX macro defaults all unused options to 0. 
#define STATE_MAP_ENTRY_ALL_EX(stateName, guardName, entryName, exitName)\
	{ stateName, guardName, entryName, exitName },

#define END_STATE_MAP_EX \
    }; \
	C_ASSERT((sizeof(STATE_MAP)/sizeof(StateMapRowEx)) == NUM_OF_STATES); \
   return &STATE_MAP[0]; }

#endif /// _STATE_MACHINE_H
