// kopy.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <limits.h>
#include "kopy.h"

// DLL internal state variables:
static unsigned long long sum_;  // Previous value, if any
static bool initalized_ = false;

// Starts the sum
void add_init(const unsigned long long start_value)
{
    sum_ = start_value;
    initalized_ = true;
}

// Adds number to sum
bool add_num(const unsigned long long num_in)
{
    if (!initalized_) {
        return false;
    }
    else {

        // check to see if we'd overflow result or position
        if (ULLONG_MAX - sum_ < num_in) {
            return false;
        }
        sum_ += num_in;
        return true;
    }
}

// Gets current sum
unsigned long long get_sum()
{
    if (initalized_)
        return sum_;
    else
        return 0;
}