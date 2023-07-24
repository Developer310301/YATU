#ifndef YATU_H
#define YATU_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>

static uint64_t passed_test;
static uint64_t passed_assert;
static uint64_t unpassed_assert;
static FILE* out_file;

/**
 * Type of test function that is accepted
*/
typedef void (*YTEST_FUNC)();

/**
 * Struct that define a test unit
*/
typedef struct{
    YTEST_FUNC test_func;
    const char* test_name;
} YTEST;

/**
 * Function that run all test units
 * @param test_number number of test unit to execute
 * @param tests array of @ref{YTEST} to execute
 * @param f pointer to a file stream (default stdout)
*/
void YRUN_TESTS(uint64_t test_number, YTEST tests[], FILE* f=stdout);

/**
 * Function called in order to verify an assert
 * @param condition bool condition that has to be verified
*/
void YASSERT(bool condition);

#endif