#pragma once

#ifdef KOPY_EXPORTS
#define KOPY_API __declspec(dllexport)
#else
#define KOPY_API __declspec(dllimport)
#endif

// Starts the sum
extern "C" KOPY_API void add_init(const unsigned long long start_value);

// Adds number to sum
extern "C" KOPY_API bool add_num(const unsigned long long num);

// Gets current sum
extern "C" KOPY_API unsigned long long get_sum();