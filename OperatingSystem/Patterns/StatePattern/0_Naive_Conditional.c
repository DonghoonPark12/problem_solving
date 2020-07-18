#include "Info.h"

/*
    아래와 같은 방법은 새로운 상태가 추가될 때 마다, 함수를 수정해야 하는
    단점이 존재

    상태와 행동의 분리가 없다. 
*/
typedef enum
{
    stopped,
    started
} State;

struct DigitalStopWatch
{
    /* Let a variable hold the state of our object. */
    State state;
    TimeSource source;
    Display watchDisplay;
};

void startWatch(DigitalStopWatchPtr instance)
{
    switch (instance->state) {
    case started:
        /* Already started -> do nothing. */
        break;
    case stopped:
        instance->state = started;
        break;
    default:
        error("Illegal state");
        break;
    }
}

void stopWatch(DigitalStopWatchPtr instance)
{
    switch (instance->state) {
    case started:
        instance->state = stopped;
        break;
    case stopped:
        /* Already stopped -> do nothing. */
        break;
    default:
        error("Illegal state");
        break;
    }
}