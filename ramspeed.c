/*
 * ramspeed.c
 *
 *  Created on: Jan 27, 2017
 *      Author: sonnt
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
#define LOOP16_BLOCK(BLOCK)   LOOP8_BLOCK(BLOCK); LOOP8_BLOCK(BLOCK);
#define LOOP32_BLOCK(BLOCK)   LOOP16_BLOCK(BLOCK); LOOP16_BLOCK(BLOCK);
#define LOOP64_BLOCK(BLOCK)   LOOP32_BLOCK(BLOCK); LOOP32_BLOCK(BLOCK);
#define LOOP128_BLOCK(BLOCK)  LOOP64_BLOCK(BLOCK); LOOP64_BLOCK(BLOCK);
#define LOOP256_BLOCK(BLOCK)  LOOP128_BLOCK(BLOCK); LOOP128_BLOCK(BLOCK);
#define LOOP512_BLOCK(BLOCK)  LOOP256_BLOCK(BLOCK); LOOP256_BLOCK(BLOCK);
#define LOOP1024_BLOCK(BLOCK)  LOOP512_BLOCK(BLOCK); LOOP512_BLOCK(BLOCK);
#define LOOP_BLOCK(BLOCK, n)\
        #if n == 8\
        #endif

#define TIME_TAKEN_BEGIN()\
    {                                                                                                                                     \
        struct timespec  start_, end_;                                                                                                    \
        clock_gettime(CLOCK_MONOTONIC,&start_);

#define TIME_TAKEN_END(duration_ns)                                                                                                       \
    clock_gettime(CLOCK_MONOTONIC,&end_);                                                                                             \
    duration_ns = (uint64_t)(end_.tv_sec*1000000000 + (uint64_t)end_.tv_nsec - (start_.tv_sec*1000000000 + (uint64_t)start_.tv_nsec));\
};
#pragma GCC push_options
//#pragma GCC optimize ("O0")
#define    NUMBER_LOOP (10)
#define    ARR_SIZE    (1024 * 2)

void get_ram_speed (void)
{
    uint64_t duration, speed;
    volatile register uint64_t src, loop = NUMBER_LOOP, i;
    volatile uint64_t dst[ARR_SIZE / 8] = { 0 };
    printf ("\nRam size to test: %f MBytes\nTesting writing speed .... ", (float)NUMBER_LOOP*ARR_SIZE / (1024 * 1024));
    src = (uint64_t) 0XAAAAAAAAAAAAAAAA;
    TIME_TAKEN_BEGIN()
        while (loop--)
        {
            i = sizeof(dst) / (sizeof(dst[0]));
            while (i)
            {
                i -= 256;
                dst[i + 0] = src; dst[i + 1] = src; dst[i + 2] = src; dst[i + 3] = src; dst[i + 4] = src; dst[i + 5] = src; dst[i + 6] = src; dst[i + 7] = src; dst[i + 8] = src; dst[i + 9] = src; dst[i + 10] = src; dst[i + 11] = src; dst[i + 12] = src; dst[i + 13] = src; dst[i + 14] = src; dst[i + 15] = src; dst[i + 16] = src; dst[i + 17] = src; dst[i + 18] = src; dst[i + 19] = src; dst[i + 20] = src; dst[i + 21] = src; dst[i + 22] = src; dst[i + 23] = src; dst[i + 24] = src; dst[i + 25] = src; dst[i + 26] = src; dst[i + 27] = src; dst[i + 28] = src; dst[i + 29] = src; dst[i + 30] = src; dst[i + 31] = src; dst[i + 32] = src; dst[i + 33] = src; dst[i + 34] = src; dst[i + 35] = src; dst[i + 36] = src; dst[i + 37] = src; dst[i + 38] = src; dst[i + 39] = src; dst[i + 40] = src; dst[i + 41] = src; dst[i + 42] = src; dst[i + 43] = src; dst[i + 44] = src; dst[i + 45] = src; dst[i + 46] = src; dst[i + 47] = src; dst[i + 48] = src; dst[i + 49] = src; dst[i + 50] = src; dst[i + 51] = src; dst[i + 52] = src; dst[i + 53] = src; dst[i + 54] = src; dst[i + 55] = src; dst[i + 56] = src; dst[i + 57] = src; dst[i + 58] = src; dst[i + 59] = src; dst[i + 60] = src; dst[i + 61] = src; dst[i + 62] = src; dst[i + 63] = src; dst[i + 64] = src; dst[i + 65] = src; dst[i + 66] = src; dst[i + 67] = src; dst[i + 68] = src; dst[i + 69] = src; dst[i + 70] = src; dst[i + 71] = src; dst[i + 72] = src; dst[i + 73] = src; dst[i + 74] = src; dst[i + 75] = src; dst[i + 76] = src; dst[i + 77] = src; dst[i + 78] = src; dst[i + 79] = src; dst[i + 80] = src; dst[i + 81] = src; dst[i + 82] = src; dst[i + 83] = src; dst[i + 84] = src; dst[i + 85] = src; dst[i + 86] = src; dst[i + 87] = src; dst[i + 88] = src; dst[i + 89] = src; dst[i + 90] = src; dst[i + 91] = src; dst[i + 92] = src; dst[i + 93] = src; dst[i + 94] = src; dst[i + 95] = src; dst[i + 96] = src; dst[i + 97] = src; dst[i + 98] = src; dst[i + 99] = src; dst[i + 100] = src; dst[i + 101] = src; dst[i + 102] = src; dst[i + 103] = src; dst[i + 104] = src; dst[i + 105] = src; dst[i + 106] = src; dst[i + 107] = src; dst[i + 108] = src; dst[i + 109] = src; dst[i + 110] = src; dst[i + 111] = src; dst[i + 112] = src; dst[i + 113] = src; dst[i + 114] = src; dst[i + 115] = src; dst[i + 116] = src; dst[i + 117] = src; dst[i + 118] = src; dst[i + 119] = src; dst[i + 120] = src; dst[i + 121] = src; dst[i + 122] = src; dst[i + 123] = src; dst[i + 124] = src; dst[i + 125] = src; dst[i + 126] = src; dst[i + 127] = src; dst[i + 128] = src; dst[i + 129] = src; dst[i + 130] = src; dst[i + 131] = src; dst[i + 132] = src; dst[i + 133] = src; dst[i + 134] = src; dst[i + 135] = src; dst[i + 136] = src; dst[i + 137] = src; dst[i + 138] = src; dst[i + 139] = src; dst[i + 140] = src; dst[i + 141] = src; dst[i + 142] = src; dst[i + 143] = src; dst[i + 144] = src; dst[i + 145] = src; dst[i + 146] = src; dst[i + 147] = src; dst[i + 148] = src; dst[i + 149] = src; dst[i + 150] = src; dst[i + 151] = src; dst[i + 152] = src; dst[i + 153] = src; dst[i + 154] = src; dst[i + 155] = src; dst[i + 156] = src; dst[i + 157] = src; dst[i + 158] = src; dst[i + 159] = src; dst[i + 160] = src; dst[i + 161] = src; dst[i + 162] = src; dst[i + 163] = src; dst[i + 164] = src; dst[i + 165] = src; dst[i + 166] = src; dst[i + 167] = src; dst[i + 168] = src; dst[i + 169] = src; dst[i + 170] = src; dst[i + 171] = src; dst[i + 172] = src; dst[i + 173] = src; dst[i + 174] = src; dst[i + 175] = src; dst[i + 176] = src; dst[i + 177] = src; dst[i + 178] = src; dst[i + 179] = src; dst[i + 180] = src; dst[i + 181] = src; dst[i + 182] = src; dst[i + 183] = src; dst[i + 184] = src; dst[i + 185] = src; dst[i + 186] = src; dst[i + 187] = src; dst[i + 188] = src; dst[i + 189] = src; dst[i + 190] = src; dst[i + 191] = src; dst[i + 192] = src; dst[i + 193] = src; dst[i + 194] = src; dst[i + 195] = src; dst[i + 196] = src; dst[i + 197] = src; dst[i + 198] = src; dst[i + 199] = src; dst[i + 200] = src; dst[i + 201] = src; dst[i + 202] = src; dst[i + 203] = src; dst[i + 204] = src; dst[i + 205] = src; dst[i + 206] = src; dst[i + 207] = src; dst[i + 208] = src; dst[i + 209] = src; dst[i + 210] = src; dst[i + 211] = src; dst[i + 212] = src; dst[i + 213] = src; dst[i + 214] = src; dst[i + 215] = src; dst[i + 216] = src; dst[i + 217] = src; dst[i + 218] = src; dst[i + 219] = src; dst[i + 220] = src; dst[i + 221] = src; dst[i + 222] = src; dst[i + 223] = src; dst[i + 224] = src; dst[i + 225] = src; dst[i + 226] = src; dst[i + 227] = src; dst[i + 228] = src; dst[i + 229] = src; dst[i + 230] = src; dst[i + 231] = src; dst[i + 232] = src; dst[i + 233] = src; dst[i + 234] = src; dst[i + 235] = src; dst[i + 236] = src; dst[i + 237] = src; dst[i + 238] = src; dst[i + 239] = src; dst[i + 240] = src; dst[i + 241] = src; dst[i + 242] = src; dst[i + 243] = src; dst[i + 244] = src; dst[i + 245] = src; dst[i + 246] = src; dst[i + 247] = src; dst[i + 248] = src; dst[i + 249] = src; dst[i + 250] = src; dst[i + 251] = src; dst[i + 252] = src; dst[i + 253] = src; dst[i + 254] = src; dst[i + 255] = src;
            };
        }
        TIME_TAKEN_END(duration)
    speed = (uint64_t) ((uint64_t) ARR_SIZE * NUMBER_LOOP * 1000000000 / (1024 * 1024 * duration));
    printf (": %"PRIu64" MB/s\n", speed);
    loop = NUMBER_LOOP;
    printf ("\nTesting reading speed .... ");
    memset ((void *) dst, 0XAA, sizeof(dst));
    TIME_TAKEN_BEGIN()
        while (loop--)
        {
            i = sizeof(dst) / (sizeof(dst[0]));
            while (i)
            {
                i = i - 256;
                src = dst[i + 0]; src = dst[i + 1]; src = dst[i + 2]; src = dst[i + 3]; src = dst[i + 4]; src = dst[i + 5]; src = dst[i + 6]; src = dst[i + 7]; src = dst[i + 8]; src = dst[i + 9]; src = dst[i + 10]; src = dst[i + 11]; src = dst[i + 12]; src = dst[i + 13]; src = dst[i + 14]; src = dst[i + 15]; src = dst[i + 16]; src = dst[i + 17]; src = dst[i + 18]; src = dst[i + 19]; src = dst[i + 20]; src = dst[i + 21]; src = dst[i + 22]; src = dst[i + 23]; src = dst[i + 24]; src = dst[i + 25]; src = dst[i + 26]; src = dst[i + 27]; src = dst[i + 28]; src = dst[i + 29]; src = dst[i + 30]; src = dst[i + 31]; src = dst[i + 32]; src = dst[i + 33]; src = dst[i + 34]; src = dst[i + 35]; src = dst[i + 36]; src = dst[i + 37]; src = dst[i + 38]; src = dst[i + 39]; src = dst[i + 40]; src = dst[i + 41]; src = dst[i + 42]; src = dst[i + 43]; src = dst[i + 44]; src = dst[i + 45]; src = dst[i + 46]; src = dst[i + 47]; src = dst[i + 48]; src = dst[i + 49]; src = dst[i + 50]; src = dst[i + 51]; src = dst[i + 52]; src = dst[i + 53]; src = dst[i + 54]; src = dst[i + 55]; src = dst[i + 56]; src = dst[i + 57]; src = dst[i + 58]; src = dst[i + 59]; src = dst[i + 60]; src = dst[i + 61]; src = dst[i + 62]; src = dst[i + 63]; src = dst[i + 64]; src = dst[i + 65]; src = dst[i + 66]; src = dst[i + 67]; src = dst[i + 68]; src = dst[i + 69]; src = dst[i + 70]; src = dst[i + 71]; src = dst[i + 72]; src = dst[i + 73]; src = dst[i + 74]; src = dst[i + 75]; src = dst[i + 76]; src = dst[i + 77]; src = dst[i + 78]; src = dst[i + 79]; src = dst[i + 80]; src = dst[i + 81]; src = dst[i + 82]; src = dst[i + 83]; src = dst[i + 84]; src = dst[i + 85]; src = dst[i + 86]; src = dst[i + 87]; src = dst[i + 88]; src = dst[i + 89]; src = dst[i + 90]; src = dst[i + 91]; src = dst[i + 92]; src = dst[i + 93]; src = dst[i + 94]; src = dst[i + 95]; src = dst[i + 96]; src = dst[i + 97]; src = dst[i + 98]; src = dst[i + 99]; src = dst[i + 100]; src = dst[i + 101]; src = dst[i + 102]; src = dst[i + 103]; src = dst[i + 104]; src = dst[i + 105]; src = dst[i + 106]; src = dst[i + 107]; src = dst[i + 108]; src = dst[i + 109]; src = dst[i + 110]; src = dst[i + 111]; src = dst[i + 112]; src = dst[i + 113]; src = dst[i + 114]; src = dst[i + 115]; src = dst[i + 116]; src = dst[i + 117]; src = dst[i + 118]; src = dst[i + 119]; src = dst[i + 120]; src = dst[i + 121]; src = dst[i + 122]; src = dst[i + 123]; src = dst[i + 124]; src = dst[i + 125]; src = dst[i + 126]; src = dst[i + 127]; src = dst[i + 128]; src = dst[i + 129]; src = dst[i + 130]; src = dst[i + 131]; src = dst[i + 132]; src = dst[i + 133]; src = dst[i + 134]; src = dst[i + 135]; src = dst[i + 136]; src = dst[i + 137]; src = dst[i + 138]; src = dst[i + 139]; src = dst[i + 140]; src = dst[i + 141]; src = dst[i + 142]; src = dst[i + 143]; src = dst[i + 144]; src = dst[i + 145]; src = dst[i + 146]; src = dst[i + 147]; src = dst[i + 148]; src = dst[i + 149]; src = dst[i + 150]; src = dst[i + 151]; src = dst[i + 152]; src = dst[i + 153]; src = dst[i + 154]; src = dst[i + 155]; src = dst[i + 156]; src = dst[i + 157]; src = dst[i + 158]; src = dst[i + 159]; src = dst[i + 160]; src = dst[i + 161]; src = dst[i + 162]; src = dst[i + 163]; src = dst[i + 164]; src = dst[i + 165]; src = dst[i + 166]; src = dst[i + 167]; src = dst[i + 168]; src = dst[i + 169]; src = dst[i + 170]; src = dst[i + 171]; src = dst[i + 172]; src = dst[i + 173]; src = dst[i + 174]; src = dst[i + 175]; src = dst[i + 176]; src = dst[i + 177]; src = dst[i + 178]; src = dst[i + 179]; src = dst[i + 180]; src = dst[i + 181]; src = dst[i + 182]; src = dst[i + 183]; src = dst[i + 184]; src = dst[i + 185]; src = dst[i + 186]; src = dst[i + 187]; src = dst[i + 188]; src = dst[i + 189]; src = dst[i + 190]; src = dst[i + 191]; src = dst[i + 192]; src = dst[i + 193]; src = dst[i + 194]; src = dst[i + 195]; src = dst[i + 196]; src = dst[i + 197]; src = dst[i + 198]; src = dst[i + 199]; src = dst[i + 200]; src = dst[i + 201]; src = dst[i + 202]; src = dst[i + 203]; src = dst[i + 204]; src = dst[i + 205]; src = dst[i + 206]; src = dst[i + 207]; src = dst[i + 208]; src = dst[i + 209]; src = dst[i + 210]; src = dst[i + 211]; src = dst[i + 212]; src = dst[i + 213]; src = dst[i + 214]; src = dst[i + 215]; src = dst[i + 216]; src = dst[i + 217]; src = dst[i + 218]; src = dst[i + 219]; src = dst[i + 220]; src = dst[i + 221]; src = dst[i + 222]; src = dst[i + 223]; src = dst[i + 224]; src = dst[i + 225]; src = dst[i + 226]; src = dst[i + 227]; src = dst[i + 228]; src = dst[i + 229]; src = dst[i + 230]; src = dst[i + 231]; src = dst[i + 232]; src = dst[i + 233]; src = dst[i + 234]; src = dst[i + 235]; src = dst[i + 236]; src = dst[i + 237]; src = dst[i + 238]; src = dst[i + 239]; src = dst[i + 240]; src = dst[i + 241]; src = dst[i + 242]; src = dst[i + 243]; src = dst[i + 244]; src = dst[i + 245]; src = dst[i + 246]; src = dst[i + 247]; src = dst[i + 248]; src = dst[i + 249]; src = dst[i + 250]; src = dst[i + 251]; src = dst[i + 252]; src = dst[i + 253]; src = dst[i + 254]; src = dst[i + 255];
            }
        }
        TIME_TAKEN_END(duration)
    speed = (uint64_t) ((uint64_t) ARR_SIZE * NUMBER_LOOP * 1000000000 / (1024 * 1024 * duration));
    printf (": %"PRIu64" MB/s\n", speed);
}
#pragma GCC pop_options
int main (void)
{
    get_ram_speed ();
    return 1;
}

