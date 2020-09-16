#include"Foo.h"
#include<iostream>
#include <unistd.h>

using namespace std;


void Foo::wait(){
	pthread_join(this->threadFoo,NULL);
}
Foo::Foo(){

	this->execTimer =ExecTimer::getInstance();

	int res = pthread_create(&this->threadFoo,NULL,&Foo::Run,this);

}
void *Foo::Run(void *arg){
	Foo * ptr = (Foo *)arg;
	int countUp = 0 ;
	while(countUp < 10){

		ptr->doJobFoo();


		ptr->doJobFromFoo();
		countUp += 1;


	}
	return NULL;

}

Foo::~Foo(){
    this->execTimer->ShutDown();
    pthread_cancel(this->threadFoo);
}
void Foo::doJobFoo(){
    execTimer->Begin();
    int t=0;
    for (int i =0 ; i< 1000000;i++){

    	t+= i ;
    }
    execTimer->End(__func__);

}   
void Foo::doJobFromFoo(){
	execTimer->Begin();
	 int t=0;
	 for (int i =0 ; i< 1000000;i++){

	    	t+= i ;
	 }
	execTimer->End(__func__);

}
