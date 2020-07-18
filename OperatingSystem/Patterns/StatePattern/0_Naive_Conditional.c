#include "Info.h"

/*
    �Ʒ��� ���� ����� ���ο� ���°� �߰��� �� ����, �Լ��� �����ؾ� �ϴ�
    ������ ����

    ���¿� �ൿ�� �и��� ����. 
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