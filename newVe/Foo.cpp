#include"Foo.h"
#include<iostream>
#include <unistd.h>

using namespace std;
//mqd_t ExecTimer::mq = (mqd_t)-1;

void Foo::wait(){
	pthread_join(this->threadFoo,NULL);
}
Foo::Foo(){

	this->execTimer =ExecTimer::getInstance();
	//this->execTimer->StartUp();
	int res = pthread_create(&this->threadFoo,NULL,&Foo::Run,this);

}
void *Foo::Run(void *arg){
	Foo * ptr = (Foo *)arg;
	//while(true){

		ptr->doJobFoo();


		ptr->doJobFromFoo();


	//}
	return NULL;

}

Foo::~Foo(){
    this->execTimer->ShutDown();
    pthread_cancel(this->threadFoo);
}
void Foo::doJobFoo(){
    execTimer->Begin();

    sleep(5);
    execTimer->End(__func__);

}   
void Foo::doJobFromFoo(){
	execTimer->Begin();

	sleep(10);
	    execTimer->End(__func__);

}
