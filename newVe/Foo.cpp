#include"Foo.h"
#include<iostream>
#include <unistd.h>

using namespace std;
//mqd_t ExecTimer::mq = (mqd_t)-1;

void Foo::wait(){
	pthread_join(this->threadFoo,NULL);
}
Foo::Foo(){
	cout << "Foo constructor\n";
	this->execTimer =ExecTimer::getInstance();
	//this->execTimer->StartUp();
	int res = pthread_create(&this->threadFoo,NULL,&Foo::Run,this);
	cout << "Foo const exit\n";
}
void *Foo::Run(void *arg){
	Foo * ptr = (Foo *)arg;
	while(true){
		ptr->doJobFoo();
		sleep(3);
		ptr->doJobFromFoo();


	}
	return NULL;

}

Foo::~Foo(){
    this->execTimer->ShutDown();
    pthread_cancel(this->threadFoo);
}
void Foo::doJobFoo(){
    execTimer->Begin();

    int t = 0 ;

    for (int i = 0; i< 100000;i++){
        t+=i;

    }
    execTimer->End(__func__);

}   
void Foo::doJobFromFoo(){
	execTimer->Begin();

	    int t = 0 ;

	    for (int i = 0; i< 100000;i++){
	        t+=i;

	    }
	    execTimer->End(__func__);

}
