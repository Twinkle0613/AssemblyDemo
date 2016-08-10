#ifndef __SAVE_REGISTERS_H__
#define __SAVE_REGISTERS_H__
#include "TCB.h"

void saveRegs(void);
void releaseRegs(void);
void loadValue(void);
void saveRegsToCPUstack(void);
void popValue(void);
void passCPUspAddressToMemory(void);
void storeLRtoMemory(void);
void copyLRfromMemorytoStack(void);
void popr4Andlr(void);
void copySP(uint32_t* sp);
#endif	// __SAVE_REGISTERS_H__
