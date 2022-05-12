// AUTHOR:		https://www.codeproject.com/Articles/1087619/State-Machine-Design-in-Cplusplus-2
// PROJECT:		WorldPerception
// DOCUMENT:	None
// DESCRIPTION: This file defines state machine

#include "state_machine.h"

StateMachine::StateMachine(unsigned char maxStates, unsigned char initialState) :
	MAX_STATES(maxStates),
	m_currentState(initialState),
	m_newState(false),
	m_eventGenerated(false),
	m_pEventData(NULL)
{
	ASSERT_TRUE(MAX_STATES < EVENT_IGNORED);
}  

/// To prevent preemption by another thread when the state machine is in the process of execution, 
/// the StateMachine class can use locks within the ExternalEvent() function. 
/// Before the external event is allowed to execute, a semaphore can be locked. 
/// When the external event and all internal events have been processed, the software lock is released, 
/// allowing another external event to enter the state machine instance.
/// Comments indicate where the lock and unlock should be placed if the application is multithreaded.
/// If using locks, each StateMachine object should have its own instance of a software lock.
/// This prevents a single instance from locking and preventing all other StateMachine objects from executing.
/// Note, software locks are only required if a StateMachine instance is called by multiple threads of control.
/// If not, then locks are not required.
void StateMachine::ExternalEvent(unsigned char newState, const EventData* pData)
{
	/// If we are supposed to ignore this event
	if (newState == EVENT_IGNORED)
	{
#ifndef EXTERNAL_EVENT_NO_HEAP_DATA

		/// Just delete the event data, if any
		if (pData != NULL)
		{
			delete pData; 
	    }
#endif
	}
	else
	{
		/// TODO - capture software lock here for thread-safety if necessary

#ifdef EXTERNAL_EVENT_NO_HEAP_DATA

		EventData data;

		if (pData == NULL)
		{
			pData = &data;
		}
#endif
		/// Generate the event
		InternalEvent(newState, pData);

		/// Execute the state engine. This function call will only return
		/// when all state machine events are processed.
		StateEngine();

		/// TODO - release software lock here 
	}
}

// If the destination doesn't accept event data, then the function is called with only the state we want to transition to
void StateMachine::InternalEvent(unsigned char newState, const EventData* pData)
{
	if (pData == NULL)
	{
		pData = new NoEventData();
	}

	m_pEventData = pData;
	m_eventGenerated = true;
	m_newState = newState;
}

/// The state engine executes the state functions based upon events generated. 
/// The transition map is an array of StateMapRow instances indexed by the m_currentState variable. 
/// When the StateEngine() function executes, it looks up a StateMapRow or StateMapRowEx array by calling GetStateMap() or GetStateMapEx():
void StateMachine::StateEngine(void)
{
	const StateMapRow* pStateMap = GetStateMap();

	if (pStateMap != NULL)
	{
		StateEngine(pStateMap);
	}
	else
	{
		const StateMapRowEx* pStateMapEx = GetStateMapEx();

		if (pStateMapEx != NULL)
		{
			StateEngine(pStateMapEx);
		}
		else
		{
			ASSERT();
		}
	}
}

/// This overloaded state engine function handles state machines with a StateMapRow table containing only the State feature.
/// The StateMapRow engine implements only #1 and #5. The extended StateMapRowEx engine uses the entire logic sequence.
/// 1. Evaluate the state transition table. If EVENT_IGNORED, the event is ignored and the transition is not performed. 
///    If CANNOT_HAPPEN, the software faults. Otherwise, continue with next step.
/// 5. Call the state action function for the new state. The new state is now the current state.
void StateMachine::StateEngine(const StateMapRow* const pStateMap)
{
#if EXTERNAL_EVENT_NO_HEAP_DATA
	bool externalEvent = true;
#endif
	const EventData* pDataTemp = NULL;	

	/// While events are being generated keep executing states
	while (m_eventGenerated)
	{
		/// Error check that the new state is valid before proceeding
		ASSERT_TRUE(m_newState < MAX_STATES);

		/// Indexing into the StateMapRow table with a new state value a state function is executed by calling InvokeStateAction() below
		/// Get the pointer from the state map
		const StateBase* state = pStateMap[m_newState].State;

		/// Copy of event data pointer
		pDataTemp = m_pEventData;

		/// Event data used up, reset the pointer
		m_pEventData = NULL;

		/// Event used up, reset the flag
		m_eventGenerated = false;

		/// Switch to the new current state
		SetCurrentState(m_newState);

		/// Execute the state action passing in event data
		ASSERT_TRUE(state != NULL);
		state->InvokeStateAction(this, pDataTemp);

		/// After the state function has a chance to execute, it deletes the event data, 
		/// if any, before checking to see if any internal events have been generated. 
#if EXTERNAL_EVENT_NO_HEAP_DATA

		if (pDataTemp)
		{
			if (!externalEvent)
			{
				/// If event data has been used, then delete it
				delete pDataTemp;
			}

			pDataTemp = NULL;
		}

		externalEvent = false;
#else
		if (pDataTemp)
		{
			delete pDataTemp;
			pDataTemp = NULL;
		}
#endif
	}
}

/// This overloaded state engine function handles state machines with a StateMapRowEx table containing the additional Guard/Entry/Exit features.
/// The state engine logic for Guard, Entry, State, and Exit actions is expressed by the following sequence. 
/// 1. Evaluate the state transition table. If EVENT_IGNORED, the event is ignored and the transition is not performed. 
///    If CANNOT_HAPPEN, the software faults. Otherwise, continue with next step.
/// 2. If a guard condition is defined execute the guard condition function. 
///    If the guard condition returns false, the state transition is ignored and the state function is not called.
///    If the guard returns true, or if no guard condition exists, the state function will be executed.
/// 3. If transitioning to a new state and an exit action is defined for the current state, call the current state exit action function.
/// 4. If transitioning to a new state and an entry action is defined for the new state, call the new state entry action function.
/// 5. Call the state action function for the new state. The new state is now the current state.
void StateMachine::StateEngine(const StateMapRowEx* const pStateMapEx)
{
#if EXTERNAL_EVENT_NO_HEAP_DATA
	bool externalEvent = true;
#endif
	const EventData* pDataTemp = NULL;

	/// While events are being generated keep executing states
	while (m_eventGenerated)
	{
		/// Error check that the new state is valid before proceeding
		ASSERT_TRUE(m_newState < MAX_STATES);

		/// Get the pointers from the state map
		const StateBase* state = pStateMapEx[m_newState].State;
		const GuardBase* guard = pStateMapEx[m_newState].Guard;
		const EntryBase* entry = pStateMapEx[m_newState].Entry;
		const ExitBase* exit = pStateMapEx[m_currentState].Exit;

		/// Copy of event data pointer
		pDataTemp = m_pEventData;

		/// Event data used up, reset the pointer
		m_pEventData = NULL;

		/// Event used up, reset the flag
		m_eventGenerated = false;

		/// Execute the guard condition
		bool guardResult = true;
		if (guard != NULL)
		{
			guardResult = guard->InvokeGuardCondition(this, pDataTemp);
		}

		/// If the guard condition succeeds
		if (guardResult == true)
		{
			/// Transitioning to a new state?
			if (m_newState != m_currentState)
			{
				/// Execute the state exit action on current state before switching to new state
				if (exit != NULL)
					exit->InvokeExitAction(this);

				/// Execute the state entry action on the new state
				if (entry != NULL)
					entry->InvokeEntryAction(this, pDataTemp);

				/// Ensure exit/entry actions didn't call InternalEvent by accident 
				ASSERT_TRUE(m_eventGenerated == false);
			}

			/// Switch to the new current state
			SetCurrentState(m_newState);

			/// Execute the state action passing in event data
			ASSERT_TRUE(state != NULL);
			state->InvokeStateAction(this, pDataTemp);
		}

		/// If event data was used, then delete it
#if EXTERNAL_EVENT_NO_HEAP_DATA

		if (pDataTemp)
		{
			if (!externalEvent)
				delete pDataTemp;

			pDataTemp = NULL;
		}

		externalEvent = false;
#else
		if (pDataTemp)
		{
			delete pDataTemp;
			pDataTemp = NULL;
		}
#endif
	}
}