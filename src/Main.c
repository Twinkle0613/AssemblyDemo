/**
 * Study the code by stepping through using debugger. Take note
 * of the stack memory, registers, variables declared in 'Main.c'
 * and 'AssemblyModule.s'.
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "AssemblyModule.h"
#include "SaveRegisters.h"
#include "Linklist.h"
#include "TCB.h"
#include "stm32f4xx_hal.h"

extern int fourBytes;						// Import from AssemblyModule.s
extern uint16_t twoBytes;				// Import from AssemblyModule.s
uint32_t lrStorage;
uint32_t r4Storage;


uint32_t variableInC = 0xdeaf;
uint32_t tempSP;
LinkedlistTcb* root;
void taskOne(void);
void taskTwo(void);

void taskOne(void){
 
   while(1){
     
   }
}

void taskTwo(void){
  while(1){
    
  }
 
}
void waitForever(void) {
	volatile int counter = 500000;
	while(counter--);
//	NVIC_DisableIRQ(SysTick_IRQn);
	disableSysTickInterrupt();
}


int main() {
  int i = 0;
	root = &tcbRoot;
  
	initTask1Tcb(taskOne);  
  initTask2Tcb(taskTwo);  
  initTaskCPU();
  tcbRootInit();
	
	addList(root,&taskCPU);
	addList(root,&task1Tcb);
  addList(root,&task2Tcb);
  loadValue();
	
	initSysTick();
	while(1) {
		i++;
	}
}

int cFunc() {
	return 0xc00000 + twoBytes;
}
