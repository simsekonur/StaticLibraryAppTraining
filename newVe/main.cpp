#include "Foo.h"
#include "FooAnother.h"
/************
 *
 * Compilation :g++ main.cpp ExecTimer.cpp Dummy.cpp -lpthread -lrt
 ************ */

int main(void){


	ExecTimer * ptr = ExecTimer::getInstance();
	ptr->StartUp();

	Foo foo ;
	/*foo.doJobFoo();
	foo.doJobFromFoo();*/

	FooAnother fooAnother;


	foo.wait();
	fooAnother.wait();
	return 0;
} 
