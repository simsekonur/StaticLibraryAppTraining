/*
 * Foo2.cpp
 *
 *  Created on: Sep 7, 2020
 *      Author: onur
 */

#include<iostream>
#include "FooAnother.h"
#include <unistd.h>


void FooAnother::wait(){
	pthread_join(this->threadFoo2,NULL);
}
void * FooAnother::Run(void * arg){

    while(true){
        //int mq_send(mqd_t __mqdes,
        //const char *__msg_ptr, size_t __msg_len, unsigned int __msg_prio)
    	FooAnother * ptr = (FooAnother *)arg;
    		while(true){
    			ptr->doJobFoo2();
    			ptr->doJobFromAnother();

    		}
    		return NULL;
    }
}


FooAnother::FooAnother(){
    this->execTimer.StartUp();
    int res = pthread_create(&this->threadFoo2,NULL,FooAnother::Run,this);

}

FooAnother::~FooAnother(){
    this->execTimer.ShutDown();
    pthread_cancel(this->threadFoo2);

}
void FooAnother::doJobFoo2(){
    execTimer.Begin();

    int t = 0 ;

    for (int i = 0; i< 100000;i++){
        t+=i;

    }
    execTimer.End(__func__);

}
void FooAnother::doJobFromAnother(){
	  execTimer.Begin();
	    int t = 0 ;

	    for (int i = 0; i< 100000;i++){
	        t+=i;

	    }
	    execTimer.End(__func__);

}
