#include <sys/time.h>
#include <stdio.h>
#include "utils.h"

typedef enum
{
    OK = 0,
    FAILED = 1,
    ERROR = 2
} Result;

typedef struct
{
    int tests;
    int failures;
    int errors;
} State;

void startupBanner()
{
    printf("--------------------------------------------------------------------------------\n");
    printf(" T E S T S\n");
    printf("--------------------------------------------------------------------------------\n");
}

void finishBanner(struct timeval *timeStarted, State *state)
{
    struct timeval timeFinished;
    gettimeofday(&timeFinished, NULL);

    double timeElapsed = getTimeDiffInSeconds(timeStarted, &timeFinished);
    printf("Tests run: %d, Failures: %d, Errors: %d, Time elapsed: %.6f sec\n",
           state->tests, state->failures, state->errors,
           timeElapsed);
}

Result testNumber(State *state, const double expected, const double actual, const char *message)
{
    Result result = ERROR;

    state->tests += 1;
    if (expected == actual)
    {
        result = OK;
    }
    else
    {
        result = FAILED;
        state->failures += 1;
    }

    if (result != OK)
    {
        printf("%s Expected: %lf Actual: %lf\n", message, expected, actual);
    }

    return result;
}

void testSuite1(State *state)
{       
    testNumber(state, 4, 3, "4 is not 3");
    testNumber(state, 4, 4, "4 is 4");

    struct timeval start, finish;
    start.tv_sec = 2;
    start.tv_usec = 0;
    finish.tv_sec = 3;
    finish.tv_usec = 234567;
    testNumber(state, 1.234567, getTimeDiffInSeconds(&start, &finish), "getTimeDiffInSeconds failed.");
}

int main()
{
    struct timeval started;
    gettimeofday(&started, NULL);

    State state;
    state.tests = 0;
    state.failures = 0;
    state.errors = 0;

    startupBanner();

    testSuite1(&state);

    finishBanner(&started, &state);

    return 0;
}