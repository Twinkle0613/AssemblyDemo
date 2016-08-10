#include "TCB.h"
#include <stdio.h>

Tcb task1Tcb;
Tcb task2Tcb;
Tcb taskCPU;
/**
 * Must call this function first
 */
void initTcb() {
	task1Tcb.name = "task_1";
	task1Tcb.sp = (uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE];
}





// Study the code in AsssemblyModule.s and take note of what
// how each instruction performs its job. You need that knowledge
// to do the following:
//
// 1) Create a new assembly file called 'SaveRegisters.s'.
// 2) Write a code in assembly [in (1)] to:
//    - load SP with the value in 'task1Tcb.sp'
//    - push all registers, except R13 to the stack
// 3) Name that function as 'saveRegs'
// 4) From main() call: 
//    - initTcb()
//    - saveRegs()
// 5) Verify that the registers are in 'task1Tcb.virtualStack'
// 6) Submit your work by pushing it to GitHub

void initTaskCPU(void){
  taskCPU.name = "task_CPU";
  taskCPU.next = NULL;
  taskCPU.sp = 0;
}

void initTask1Tcb(void (*funcAddress)){
  CpuContext* context;
  task1Tcb.name = "task_1";
	task1Tcb.sp = (uint32_t)&task1Tcb.virtualStack[TASK_STACK_SIZE-68];
  task1Tcb.next = NULL;
  context = getTopAddressOfStack(&task1Tcb.virtualStack[TASK_STACK_SIZE] , sizeof(CpuContext) );
  context->R4 = 0x44444444;
	context->R5 = 0x55555555;
	context->R6 = 0x60606060;
	context->R7 = 0x07070707;
	context->R8 = 0x80808080;
	context->R9 = 0x09090909;
	context->R10 = 0x10101010;
	context->R11 = 0x11111111;
	context->ALR = 0xfffffff9;
	context->R0 = 0x01010101;
  context->R1 = 0x1111000;
  context->R2 = 0x20202020;
  context->R3 = 0x03030303;  
  context->R12 = 0x12121212;
  context->LR = 0xdeadbeef;
  context->PC = (uint32_t)funcAddress;
  context->xPSR = 0x01000000;
}

void initTask2Tcb(void (*funcAddress)){
  CpuContext* context;
  task2Tcb.name = "task_2";
	task2Tcb.sp = (uint32_t)&task2Tcb.virtualStack[TASK_STACK_SIZE-68];
  task2Tcb.next = NULL;
  context = getTopAddressOfStack(&task2Tcb.virtualStack[TASK_STACK_SIZE] , sizeof(CpuContext) );
  context->R4 = 0x44444444;
  context->R5 = 0x55555555;
  context->R6 = 0x60606060;
  context->R7 = 0x07070707;
  context->R8 = 0xcbcbcbcb;
  context->R9 = 0xccddccdd;
	context->R10 = 0x1a1a1a1a;
  context->R11 = 0xabcddddd;
  context->ALR = 0xfffffff9;
	context->R0 = 0x01010101;
  context->R1 = 0x1111000;
  context->R2 = 0x20202020;
  context->R3 = 0x03030303;
  context->R12 = 0x12c12c12;
  context->LR = 0xdeadbeef;
  context->PC = (uint32_t)funcAddress;
  context->xPSR = 0x01000000;
}

