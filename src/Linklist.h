#ifndef Linklist_H
#define Linklist_H
//#include <malloc.h>
#include <stdint.h>
#include "TCB.h"


typedef struct LinkedlistTcb_t LinkedlistTcb;

struct LinkedlistTcb_t{
	  Tcb *head;
	  Tcb *tail;
}; 

void tcbRootInit(void);
void addList(LinkedlistTcb* newList,Tcb* task);
Tcb* linkListHeadRemove(LinkedlistTcb* newList);
void saveToCurrentTcbAndGetNextTcb(LinkedlistTcb* list);

extern LinkedlistTcb tcbRoot;
extern LinkedlistTcb* root;
#endif // Linklist_H
