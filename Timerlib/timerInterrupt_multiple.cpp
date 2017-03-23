#include "timerInterrupt1.h"
#include "unistd.h"	
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define maxtimers 4
pthread_t timerThread[maxtimers];
float timePeriod[maxtimers];
struct timeval start[maxtimers], stop[maxtimers];
void (*timerfunc[maxtimers])(void);
void (*slowfuncInterrupt)(void);
bool slowFuncInterruptEnabled = false;
typedef void *(*funcptr)(void *);
funcptr arr[4]={&timerLoop0,&timerLoop1,&timerLoop2,&timerLoop3}; 

void initTimer(float timePeriod_, void (*timerHandler)(void),int i) {
	timePeriod[i] = timePeriod_;
	timerfunc[i] = timerHandler;
	pthread_create(&timerThread[i],NULL,arr[i],(void*)&i);
	
}

void stopTimer(int i){
	pthread_cancel(timerThread[i]);
}

void enableSlowFuncInterrupt(void (*interruptHandler)(void)) {
	slowfuncInterrupt = interruptHandler;
	slowFuncInterruptEnabled = true;
}



void *timerLoop0(void *args) {
	int i=0;
	gettimeofday(&start[i], NULL);
	while(1)
	{
	gettimeofday(&stop[i], NULL);
	long int timelap = timePeriod[i] -((stop[i].tv_sec * 1000000 + stop[i].tv_usec) - (start[i].tv_sec * 1000000 + start[i].tv_usec));
		if(timelap< 0) {
			if(slowFuncInterruptEnabled) {
				(*slowfuncInterrupt)();
			}
		} else {
			usleep(timelap);
		}
		gettimeofday(&start[i], NULL);
		(*timerfunc[i])();
	}	
}
void *timerLoop1(void *args) {
	int i=1;
	gettimeofday(&start[i], NULL);
	while(1)
	{
	gettimeofday(&stop[i], NULL);
	long int timelap = timePeriod[i] -((stop[i].tv_sec * 1000000 + stop[i].tv_usec) - (start[i].tv_sec * 1000000 + start[i].tv_usec));
		if(timelap< 0) {
			if(slowFuncInterruptEnabled) {
				(*slowfuncInterrupt)();
			}
		} else {
			usleep(timelap);
		}
		gettimeofday(&start[i], NULL);
		(*timerfunc[i])();
	}	
}
void *timerLoop2(void *args) {
	int i=2;
	gettimeofday(&start[i], NULL);
	while(1)
	{
	gettimeofday(&stop[i], NULL);
	long int timelap = timePeriod[i] -((stop[i].tv_sec * 1000000 + stop[i].tv_usec) - (start[i].tv_sec * 1000000 + start[i].tv_usec));
		if(timelap< 0) {
			if(slowFuncInterruptEnabled) {
				(*slowfuncInterrupt)();
			}
		} else {
			usleep(timelap);
		}
		gettimeofday(&start[i], NULL);
		(*timerfunc[i])();
	}	
}
void *timerLoop3(void *args) {
	int i=3;
	gettimeofday(&start[i], NULL);
	while(1)
	{
	gettimeofday(&stop[i], NULL);
	long int timelap = timePeriod[i] -((stop[i].tv_sec * 1000000 + stop[i].tv_usec) - (start[i].tv_sec * 1000000 + start[i].tv_usec));
		if(timelap< 0) {
			if(slowFuncInterruptEnabled) {
				(*slowfuncInterrupt)();
			}
		} else {
			usleep(timelap);
		}
		gettimeofday(&start[i], NULL);
		(*timerfunc[i])();
	}	
}
