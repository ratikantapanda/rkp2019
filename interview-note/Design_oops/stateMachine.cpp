#ifndef EVENT_DATA_H
#define EVENT_DATA_H
 
class EventData 
{
public:
    virtual ~EventData() {};  
};
#endif //EVENT_DATA_H
/*
void ExternalEvent(unsigned char, EventData* = NULL)
void InternalEvent(unsigned char, EventData* = NULL)
virtual const StateStruct* GetStateMap() = 0
*/
#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include <stdio.h>
#include "EventData.h"
 
struct StateStruct;
 
// base class for state machines
class StateMachine 
{
public:
    StateMachine(int maxStates);
    virtual ~StateMachine() {}
protected:
    enum { EVENT_IGNORED = 0xFE, CANNOT_HAPPEN };
    unsigned char currentState;
    void ExternalEvent(unsigned char, EventData* = NULL);
    void InternalEvent(unsigned char, EventData* = NULL);
    virtual const StateStruct* GetStateMap() = 0;
private:
    const int _maxStates;
    bool _eventGenerated;
    EventData* _pEventData;
    void StateEngine(void);
};
 
typedef void (StateMachine::*StateFunc)(EventData *);
struct StateStruct 
{
    StateFunc pStateFunc;    
};
 
#define BEGIN_STATE_MAP \
public:\
const StateStruct* GetStateMap() {\
    static const StateStruct StateMap[] = { 
 
#define STATE_MAP_ENTRY(entry)\
    { reinterpret_cast<StateFunc>(entry) },
 
#define END_STATE_MAP \
    { reinterpret_cast<StateFunc>(NULL) }\
    }; \
    return &StateMap[0]; }
 
#define BEGIN_TRANSITION_MAP \
    static const unsigned char TRANSITIONS[] = {\
 
#define TRANSITION_MAP_ENTRY(entry)\
    entry,
 
#define END_TRANSITION_MAP(data) \
    0 };\
    ExternalEvent(TRANSITIONS[currentState], data);
 
#endif //STATE_MACHINE_H
#include <assert.h>
#include "StateMachine.h"
 
StateMachine::StateMachine(int maxStates) :
    _maxStates(maxStates),
    currentState(0),
    _eventGenerated(false),
    _pEventData(NULL)
{
}    
 
// generates an external event. called once per external event 
// to start the state machine executing
void StateMachine::ExternalEvent(unsigned char newState, 
                                 EventData* pData)
{
    // if we are supposed to ignore this event
    if (newState == EVENT_IGNORED) {
        // just delete the event data, if any
        if (pData)  
            delete pData;
    }
    else {
        // generate the event and execute the state engine
        InternalEvent(newState, pData); 
        StateEngine();                  
    }
}
 
// generates an internal event. called from within a state 
// function to transition to a new state
void StateMachine::InternalEvent(unsigned char newState, 
                                 EventData* pData)
{
    _pEventData = pData;
    _eventGenerated = true;
    currentState = newState;
}
 
// the state engine executes the state machine states
void StateMachine::StateEngine(void)
{
    EventData* pDataTemp = NULL;
 
    // TBD - lock semaphore here
    // while events are being generated keep executing states
    while (_eventGenerated) {         
        pDataTemp = _pEventData;  // copy of event data pointer
        _pEventData = NULL;       // event data used up, reset ptr
        _eventGenerated = false;  // event used up, reset flag
 
        assert(currentState < _maxStates);
 
        // execute the state passing in event data, if any
        const StateStruct* pStateMap = GetStateMap();
        (this->*pStateMap[currentState].pStateFunc)(pDataTemp);
 
        // if event data was used, then delete it
        if (pDataTemp) {
            delete pDataTemp;
            pDataTemp = NULL;
        }
    }
    // TBD - unlock semaphore here
}
#ifndef MOTOR_H
#define MOTOR_H
#include "StateMachine.h"
 
// structure to hold event data passed into state machine
struct MotorData : public EventData
{
    int speed;
};
 
// the Motor state machine class
class Motor : public StateMachine
{
public:
    Motor() : StateMachine(ST_MAX_STATES) {}
 
    // external events taken by this state machine
    void Halt();
    void SetSpeed(MotorData*);
private:
    // state machine state functions
    void ST_Idle();
    void ST_Stop();
    void ST_Start(MotorData*);
    void ST_ChangeSpeed(MotorData*);
 
    // state map to define state function order
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(ST_Idle)
        STATE_MAP_ENTRY(ST_Stop)
        STATE_MAP_ENTRY(ST_Start)
        STATE_MAP_ENTRY(ST_ChangeSpeed)
    END_STATE_MAP
 
    // state enumeration order must match the order of state
    // method entries in the state map
    enum E_States { 
        ST_IDLE = 0,
        ST_STOP,
        ST_START,
        ST_CHANGE_SPEED,
        ST_MAX_STATES
    };
};
#endif //MOTOR_H
#include <assert.h>
#include "Motor.h"
 
// halt motor external event
void Motor::Halt(void)
{
    // given the Halt event, transition to a new state based upon 
    // the current state of the state machine
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Idle
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)  // ST_Stop
        TRANSITION_MAP_ENTRY (ST_STOP)        // ST_Start
        TRANSITION_MAP_ENTRY (ST_STOP)        // ST_ChangeSpeed
    END_TRANSITION_MAP(NULL)
}
 
// set motor speed external event
void Motor::SetSpeed(MotorData* pData)
{
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_START)       // ST_Idle       
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)  // ST_Stop       
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)// ST_Start      
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)// ST_ChangeSpeed
    END_TRANSITION_MAP(pData)
}
 
// state machine sits here when motor is not running
void Motor::ST_Idle() 
{
}
 
// stop the motor 
void Motor::ST_Stop()
{
    // perform the stop motor processing here
    // transition to ST_Idle via an internal event
    InternalEvent(ST_IDLE);
}
 
// start the motor going
void Motor::ST_Start(MotorData* pData)
{
    // set initial motor speed processing here
}
 
// changes the motor speed once the motor is moving
void Motor::ST_ChangeSpeed(MotorData* pData)
{
    // perform the change motor speed to pData->speed here
}
