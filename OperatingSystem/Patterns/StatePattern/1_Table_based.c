#include "Info.h"

#define NO_OF_STATES 2
#define NO_OF_EVENTS 2

typedef enum
{
    stopped,
    started
} State;

typedef enum
{
    stopEvent,
    startEvent
} Event;

struct DigitalStopWatch
{
    /* Let a variable hold the state of our object. */
    State state;
    TimeSource source;
    Display watchDisplay;
};

static State TransitionTable[NO_OF_STATES][NO_OF_EVENTS] =
{
  { stopped, started },
  { stopped, started }
 };

void startWatch(DigitalStopWatchPtr instance) {
    const State currentState = instance->state;

    instance->state = TransitionTable[currentState][startEvent];
}

void stopWatch(DigitalStopWatchPtr instance) {
    const State currentState = instance->state;

    instance->state = TransitionTable[currentState][stopEvent];
}

/* 
    이 방법은 확장이 용이하다(?)


*/