#ifndef timerInterrupt
#define timerInterrupt

void initTimer(float timePeriod_, void (*timerHandler)(void),int i);
void stopTimer(int i);
void enableSlowFuncInterrupt(void (*interruptHandler)(void));
void time(int i);
void *timerLoop1(void*);
void *timerLoop2(void*);
void *timerLoop3(void*);
void *timerLoop0(void*);
#endif
