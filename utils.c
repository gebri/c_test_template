#include <sys/time.h>

double getTimeDiffInSeconds(struct timeval *startTimeVal, struct timeval *finishTimeVal)
{
    time_t start = ((startTimeVal->tv_sec) * 1000000) + startTimeVal->tv_usec;
    time_t finish = ((finishTimeVal->tv_sec) * 1000000) + finishTimeVal->tv_usec;

    return (finish - start) / 1000000.0;
}