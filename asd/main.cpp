// main
#include "ExecTimer.h"

int main(void){
	ExecTimer et;
	et.StartUp();
	et.Send();
	et.Wait();
	return 0;
} 
