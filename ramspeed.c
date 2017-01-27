/*
 * ramspeed.c
 *
 *  Created on: Jan 27, 2017
 *      Author: sonnt <thanhson.rf@gmail.com>
 */
#include <signal.h>
#include <time.h>     /*timeval*/
#include <inttypes.h> /*PRIu64 for printf*/
#include <stdlib.h>   /*malloc, free*/
#include <getopt.h>   /*getopt()*/
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#define LOOP8_BLOCK(BLOCK)    BLOCK; BLOCK; BLOCK; BLOCK; BLOCK; BLOCK; BLOCK; BLOCK;
#define LOOP16_BLOCK(BLOCK)   LOOP8_BLOCK(BLOCK);    LOOP8_BLOCK(BLOCK);
#define LOOP32_BLOCK(BLOCK)   LOOP16_BLOCK(BLOCK);   LOOP16_BLOCK(BLOCK);
#define LOOP64_BLOCK(BLOCK)   LOOP32_BLOCK(BLOCK);   LOOP32_BLOCK(BLOCK);
#define LOOP128_BLOCK(BLOCK)  LOOP64_BLOCK(BLOCK);   LOOP64_BLOCK(BLOCK);
#define LOOP256_BLOCK(BLOCK)  LOOP128_BLOCK(BLOCK);  LOOP128_BLOCK(BLOCK);
#define LOOP512_BLOCK(BLOCK)  LOOP256_BLOCK(BLOCK);  LOOP256_BLOCK(BLOCK);
#define LOOP1024_BLOCK(BLOCK)  LOOP512_BLOCK(BLOCK); LOOP512_BLOCK(BLOCK);
#define LOOP_BLOCK(BLOCK, n)

#define TIME_TAKEN_BEGIN()                                                                                                                \
    {                                                                                                                                     \
        struct timespec  start_, end_;                                                                                                    \
        clock_gettime(CLOCK_MONOTONIC,&start_);

#define TIME_TAKEN_END(duration_ns)                                                                                                       \
        clock_gettime(CLOCK_MONOTONIC,&end_);                                                                                             \
        duration_ns = (uint64_t)(end_.tv_sec*1000000000 + (uint64_t)end_.tv_nsec - (start_.tv_sec*1000000000 + (uint64_t)start_.tv_nsec));\
    };
#pragma GCC push_options
#pragma GCC optimize ("O0")
#define    NUMBER_LOOP (1024)
#define    ARR_SIZE    (1024 * 1024)

void get_ram_speed (void)
{
    uint64_t duration, speed;
    volatile register uint64_t src, loop = NUMBER_LOOP;
    volatile uint64_t dst[ARR_SIZE / 8] = { 0 };
    printf ("\nRam size to test: %f MBytes\n\nTesting writing speed .... ", (float)NUMBER_LOOP*ARR_SIZE / (1024 * 1024));
    src = (uint64_t) 0XAAAAAAAAAAAAAAAA;
    TIME_TAKEN_BEGIN()
        while (loop--)
        {
            #include "dst_src.h"
        }
        TIME_TAKEN_END(duration)
    speed = (uint64_t) ((uint64_t) ARR_SIZE * NUMBER_LOOP * 1000000000 / (1024 * 1024) / duration);
    printf (": %"PRIu64" MB/s", speed);
    loop = NUMBER_LOOP;
    printf ("\nTesting reading speed .... ");
    memset ((void *) dst, 0XAA, sizeof(dst));
    TIME_TAKEN_BEGIN()
        while (loop--)
        {
            #include "src_dst.h"
        }
        TIME_TAKEN_END(duration)
    speed = (uint64_t) ((uint64_t) ARR_SIZE * NUMBER_LOOP * 1000000000 / (1024 * 1024) / duration);
    printf (": %"PRIu64" MB/s\n", speed);
}
#pragma GCC pop_options
int main (void)
{
    get_ram_speed ();
    return 1;
}

