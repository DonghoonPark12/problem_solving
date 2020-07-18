#ifndef DIGITAL_STOP_WATCH_H
#define DIGITAL_STOP_WATCH_H

/*
A pointer to an incomplete type (hides the implementation details).
*/
typedef struct DigitalStopWatch* DigitalStopWatchPtr;

typedef struct
{
    int some;
    int display;
    int properties;
} Display;

typedef struct
{
    const char* someSourceHere;
} TimeSource;

void error(const char* reason);


#endif