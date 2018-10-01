

__asm int my_sqrt(int x){
	PUSH {r4, r5, r6, r7, r8}   //push all needed registers
	

	
	MOVS r1, #0      //initialize done = 0
	MOVS r2, #0      //initialize a = 0
	MOVS r3, #65536  //initialize b = largest number
	MOVS r4, #-1     //initialize c = -1
	MOVS r5, #0     //initialize c_old
	MOVS r6, #0     //initialize placeholder
	MOVS r7, #2     //initialize divisor 
	

main_fn
	CMP r4, r5
	BEQ return_c
	MOVS r5, r4      //c is pushed to c_old
	ADD  r4, r2, r3  //a+b
	UDIV  r4, r4, r7 //(a+b) / 2 =  c
	MUL  r6, r4, r4  //then c*c
	CMP r6, r0      //main if: c*c = x?
	BEQ finished    //if yes, finished
	CMP r6, r0      //c*c < x
	BLT control    
	MOVS r3, r4     //else c-> b
	b check_if_cont

control
	MOVS r2, r4      //else if c->a
	b check_if_cont

finished
	MOVS r1, #1    //done = 1  

check_if_cont
	CMP r1, #1    //if done=1, done  
	BNE main_fn   
	CMP r5, r4    //c_old!=c  
	BEQ main_fn 

return_c
	MOVS r0, r4 //return c
	POP {r4, r5, r6, r7, r8} //pop all registers
	BX lr  //out
	


}






/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
int main(void){
	volatile int r, j=0;
	int i;
	r = my_sqrt(0); //answer should be: 0
	r = my_sqrt(25); //5
	r = my_sqrt(133); //11
  for (i=0; i<10000; i++){
		r = my_sqrt(i);
    j+=r;           //should be 661650
  }
	while(1)
		;
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014**************************************/

