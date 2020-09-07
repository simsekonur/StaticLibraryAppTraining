#include"Foo.h"
#include<iostream>
#include <unistd.h>


//mqd_t ExecTimer::mq = (mqd_t)-1;


Foo::Foo(){
	this->execTimer.StartUp();

	int res = pthread_create(&this->threadFoo,NULL,Run,NULL);
}
void *Foo::Run(void *arg){

	while(true){

		doJobFoo();


	}
}

Foo::~Foo(){
    this->execTimer.ShutDown();
    pthread_cancel(this->threadFoo);
}
void Foo::doJobFoo(){
    execTimer.Begin();

    int t = 0 ;

    for (int i = 0; i< 100000;i++){
        t+=i;

    }
    execTimer.End(__func__);
    std::cout << "Tamamen dummy\n";
}   
