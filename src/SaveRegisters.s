

                AREA    MyCode, CODE, READONLY
saveRegs		  	PROC
                EXPORT saveRegs
                IMPORT tempSP
								ldr sp,=tempSP
								ldr sp,[sp]
								push {r4,r5,r6,r7,r8,r9,r10,r11}
                
								bx	lr
								
								ENDP					
									
									
releaseRegs		  PROC
                EXPORT releaseRegs
                IMPORT tempSP
								ldr sp,=tempSP
								ldr sp,[sp]
								pop {r4,r5,r6,r7,r8,r9,r10,r11}
								bx	lr
								
								ENDP						
									
saveRegsToCPUstack     PROC
	              EXPORT saveRegsToCPUstack
								push {r4,r5,r6,r7,r8,r9,r10,r11}
								bx	lr
								ENDP	

popValue 	      PROC
							  EXPORT popValue
								pop {r1,r2}
								bx	lr
								ENDP	

storeLRtoMemory  PROC
	              EXPORT storeLRtoMemory
								IMPORT lrStorage
								pop {r1,r2}
								ldr r5, =lrStorage
								str r2,[r5]
								push {r1,r2}
								bx lr
                ENDP
						
copyLRfromMemorytoStack     PROC
	              EXPORT copyLRfromMemorytoStack
								IMPORT lrStorage
								ldr r5, =lrStorage
								ldr r5,[r5]
								push {r4,r5}
								bx lr
                ENDP

passCPUspAddressToMemory PROC
                EXPORT passCPUspAddressToMemory
							  IMPORT tempSP
								ldr r3,=tempSP
								str sp,[r3]
								bx lr
								ENDP

popr4Andlr     PROC 
	             EXPORT popr4Andlr
							 pop {r4,lr}
							 bx lr
							 ENDP
								 
loadValue       PROC
	              EXPORT loadValue
								mov			r0, #0x0f
								mov			r1, #0x11
								mov			r2, #0x22
								mov			r3, #0x33
								mov			r4, #0x44
								mov			r5, #0x55
								mov			r6, #0x66
								mov			r7, #0x77
								mov			r8, #0x88
								mov			r9, #0x99
								mov			r10, #0x10
								mov			r11, #0x1F
								mov			r12, #0x12
								
								bx lr
								ENDP
									
								END