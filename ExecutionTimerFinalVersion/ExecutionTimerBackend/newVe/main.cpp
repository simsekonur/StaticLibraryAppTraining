#include "Foo.h"
#include "FooAnother.h"
#include<iostream>
/************
 *
 * Compilation :g++ main.cpp ExecTimer.cpp Dummy.cpp -lpthread -lrt
 ************ */

int main(void){

	ExecTimer * ptr = ExecTimer::getInstance();
	// We are creating execTimer's thread.
	// Run function in ExecTimer will start to wait for receiving a message
	ptr->StartUp();

	//We are not calling any function of foo 
	//Foo constructor will create a thread for its class 
	// where all of the functions inside this class can be invoked.
	Foo foo ;
	FooAnother fooAnother;

	
	foo.wait();
	fooAnother.wait();

	return 0;
} 
