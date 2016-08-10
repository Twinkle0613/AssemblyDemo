//General Library

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <malloc.h>
//Own Library
#include "Linklist.h"
#include "SaveRegisters.h"
LinkedlistTcb tcbRoot;

void tcbRootInit(void){
  tcbRoot.head = NULL;
  tcbRoot.tail = NULL;
}

void addList(LinkedlistTcb* newList,Tcb* task){
	 if(newList->head == NULL)
	 {
      newList->head = task;
	 }
	 else 
	 {
		 for(newList->tail = newList->head; newList->tail->next!=NULL ; newList->tail = newList->tail->next ){};
     newList->tail->next = task;
	 }
}

Tcb* linkListHeadRemove(LinkedlistTcb* newList){
       
   Tcb* temp = newList->head;
   if(newList->head->next != NULL){
    newList->head = newList->head->next;
   }else{
    newList->head = NULL;
   }   
   temp->next = NULL;   
   return temp;      
  
}


#define dequeue(x) linkListHeadRemove(x)
#define queue(y,x) addList(y,x)
#define peepHeadSP(x) (x->head->sp)
#define getCPUspAddressFromMemory() (tempSP)
#define getExpireTaskSP temp->sp

uint32_t saveToCurrentTcbAndGetNextTcb(LinkedlistTcb* list){
		Tcb* temp;	
	  temp = dequeue(list);	
	  copySP(&temp->sp);
	  queue(list,temp);
	  return (list->head->sp);
}

