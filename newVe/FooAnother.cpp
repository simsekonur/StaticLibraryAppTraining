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

    	FooAnother * ptr = (FooAnother *)arg;
    	int countUp =0 ;
    		while(countUp < 10){

    			ptr->doJobFoo2();

    			ptr->doJobFromAnother();
    			countUp +=1 ;

    		}
    		return NULL;
    }
}


FooAnother::FooAnother(){
	this->execTimer2 = ExecTimer::getInstance();

    int res = pthread_create(&this->threadFoo2,NULL,FooAnother::Run,this);

}

FooAnother::~FooAnother(){
    this->execTimer2->ShutDown();
    pthread_cancel(this->threadFoo2);

}
void FooAnother::doJobFoo2(){
    execTimer2->Begin();
    int t=0;
       for (int i =0 ; i< 1000000;i++){

       	t+= i ;
     }
    execTimer2->End(__func__);

}
void FooAnother::doJobFromAnother(){
	  execTimer2->Begin();
	  int t=0;
	     for (int i =0 ; i< 1000000;i++){

	     	t+= i ;
	  }
	  execTimer2->End(__func__);

}
