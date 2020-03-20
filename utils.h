#ifndef _UTILS_
#define _UTILS_
#include <sys/time.h>

double getTimeDiffInSeconds(struct timeval *startTimeVal, struct timeval *finishTimeVal);
#endif