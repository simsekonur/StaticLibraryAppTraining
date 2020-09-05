// main
#include "Dummy.h"

/************
 *
 * Compilation :g++ main.cpp ExecTimer.cpp Dummy.cpp -lpthread -lrt
 ************ */

int main(void){
	Dummy dummy;
	dummy.doJob();
	dummy.doJob2();
	dummy.doJob3();
	/*dummy.doJob4();
	dummy.doJob5();
	dummy.doJob6();
	dummy.doJob7();
	dummy.doJob8();
	dummy.doJob9();
	dummy.doJob10();*/
	//dummy.doJob11();
	return 0;
} 
