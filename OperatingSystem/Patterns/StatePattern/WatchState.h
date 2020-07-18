/*
    테이블 기반 접근 방식은 상태 전환 정의에 중점을 두는 반면,
    STATE 패턴은 상태 별 동작을 모델링 한다.
*/

/* ------------------------------------------------------------------------ */
/* An incomplete type for the state representation itself. */
typedef struct WatchState* WatchStatePtr;

/* Simplify the code by using typedefs for the function pointers. */
typedef void (*EventStartFunc)(WatchStatePtr);
typedef void (*EventStopFunc) (WatchStatePtr);

struct WatchState
{
    char* name;
    EventStartFunc start;
    EventStopFunc stop;
};
/* ------------------------------------------------------------------------ */

void transitionToStarted(WatchStatePtr state); //prototype
void transitionToStopped(WatchStatePtr state); //prototype


static void defaultStop(WatchStatePtr state) {
  /* We'll get here if the stop event isn't supported
     in the concrete state. */
}

static void defaultStart(WatchStatePtr state) {
    /* We'll get here if the start event isn't supported
       in the concrete state. */
}

void defaultImplementation(WatchStatePtr state) {
    state->start = defaultStart;
    state->stop = defaultStop;
}

/* ------------------------------------------------------------------------ */
static void startWatch(WatchStatePtr state){
    transitionToStarted(state);
}

void transitionToStopped(WatchStatePtr state){
    /* Initialize with the default implementation before
       specifying the events to be handled in the stopped
       state. */
    defaultImplementation(state);
    state->name = "Stopped";
    state->start = startWatch; //Function to FunctionPointer
}
/* ------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------ */
static void stopWatch(WatchStatePtr state){
    transitionToStopped(state);
}

void transitionToStarted(WatchStatePtr state){
    /* Initialize with the default implementation before
       specifying the events to be handled in the started
       state. */
    defaultImplementation(state);
    state->stop = stopWatch; //Function to FunctionPointer
}
/* ------------------------------------------------------------------------ */
