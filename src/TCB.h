#ifndef __TCB_H__
#define __TCB_H__

#include <stdint.h>

#define TASK_STACK_SIZE	1024
#define getTopAddressOfStack(x,y) ((CpuContext*)(x - y))
typedef struct Tcb_t Tcb;

void initTcb(void);
void initTask1Tcb(void (*funcAddress));
void initTask2Tcb(void (*funcAddress));
void initTaskCPU(void);

 
struct Tcb_t{
	Tcb* next;
	char *name;									// Task name	
	uint32_t 	sp;								// Stack pointer (R13)
	uint8_t		virtualStack[TASK_STACK_SIZE];
};

typedef struct{
 uint32_t R4;
 uint32_t R5;
 uint32_t R6;
 uint32_t R7;
 uint32_t R8;
 uint32_t R9;
 uint32_t R10;
 uint32_t R11;
 uint32_t R0;
 uint32_t R1;
 uint32_t R2;
 uint32_t R3;
 uint32_t R12;
 uint32_t LR;	
 uint32_t PC;	
 uint32_t xPSR;
}CpuContext;
	

extern Tcb task1Tcb;
extern Tcb task2Tcb;
extern Tcb taskCPU;
extern uint32_t tempSP;
extern uint32_t lrStorage;
extern uint32_t r4Storage;

#endif	// __TCB_H__
