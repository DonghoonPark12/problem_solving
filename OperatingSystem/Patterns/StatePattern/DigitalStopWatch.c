//#include "DigitalStopWatch.h"

/* We need to know about or initial state: */
//#include "StoppedState.h"

#include "WatchState.h"
#include "info.h"
#include <stdlib.h>

/*
A pointer to an incomplete type (hides the implementation details).
*/
typedef struct DigitalStopWatch* DigitalStopWatchPtr;

struct DigitalStopWatch {
    struct WatchState state;
    TimeSource source;
    Display watchDisplay;
};

/*
A watch is implemented using the First-Class ADT pattern.
*/
DigitalStopWatchPtr createWatch(void);             //prototype
void destroyWatch(DigitalStopWatchPtr instance);   //prototype
void startWatch(DigitalStopWatchPtr instance);     //prototype
void stopWatch(DigitalStopWatchPtr instance);      //prototype


DigitalStopWatchPtr createWatch(void) {
  DigitalStopWatchPtr instance = malloc(sizeof *instance);

  if(NULL != instance) {
    /* Specify the initial state. */
    transitionToStopped(&instance->state);
    /* Initialize the other attributes here.*/
  }

  return instance; 
}

void destroyWatch(DigitalStopWatchPtr instance) 
{
  free(instance);
}

void startWatch(DigitalStopWatchPtr instance) 
{
  instance->state.start(&instance->state);
}

void stopWatch(DigitalStopWatchPtr instance) 
{
  instance->state.stop(&instance->state);
}


//void changeState(DigitalStopWatchPtr instance, WatchStatePtr newState) {
//    instance->state = newState;
//}