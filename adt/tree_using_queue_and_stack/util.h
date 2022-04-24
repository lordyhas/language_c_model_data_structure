#ifndef __UTIL_H__
    #define __UTIL_H__
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <time.h>
    #include <math.h>


    #define print printf
    #define printError(x) fprintf(stderr,x)
    #define N 10
    #define NIL -1
    #define NaN 0/1
    
    typedef void None;

    typedef enum BOOL {False, True} Bool;

    //struct date {int day;int month;int year;};
    //typedef struct time {int hour;int min;int sec;} Time;
    //typedef struct datetime {int hour;int min;int sec;} Datetime;

    //typedef struct date Date;

    //typedef struct list List;
    //struct list {int i; int length = sizeof(List)/List};
#endif


