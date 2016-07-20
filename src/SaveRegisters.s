

                AREA    MyCode, CODE, READONLY
saveRegs		  	PROC
                EXPORT saveRegs
                IMPORT tempSP
								;str tempSP,[sp]	
								ldr sp,=tempSP
								ldr sp,[sp]
								push {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}
                ENDP
								END