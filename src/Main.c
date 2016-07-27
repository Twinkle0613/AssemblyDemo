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

uint32_t variableInC = 0xdeaf;
uint32_t tempSP;
struct Linkedlist *root;
struct ListElement *tcbElement1;
struct ListElement *tcbElement2;
void waitForever(void) {
	volatile int counter = 500000;
	while(counter--);
//	NVIC_DisableIRQ(SysTick_IRQn);
	disableSysTickInterrupt();
}

void TIM2_IRQHandler(){
	

	
}


void TIM2_init(void){
 HAL_NVIC_EnableIRQ(TIM2_IRQn);
 __HAL_RCC_TIM2_CLK_ENABLE();
 __HAL_RCC_TIM2_RELEASE_RESET();
	
}

int main() {
  int i;
	i = 2;
	initTcb();
  root = createLinkedList();
  tcbElement1 = createLinkedElement(1,"task1");
	tcbElement2 = createLinkedElement(2,"task2");
	
	addList(root,tcbElement1);
	addList(root,tcbElement2);
	
	fourBytes = 0xdeadbeef;
	tempSP = task1Tcb.sp;
	
  saveRegs();
	initSysTick();


	while(1) {
		
	}

//	return 0;				// Verify that 'variableInC' now contains 0xB19FACE
}

int cFunc() {
	return 0xc00000 + twoBytes;
}
