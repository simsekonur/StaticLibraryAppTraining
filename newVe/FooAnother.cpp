/*
 * Foo2.cpp
 *
 *  Created on: Sep 7, 2020
 *      Author: onur
 */

#include<iostream>
#include "FooAnother.h"

myExecResult * FooAnother::resultsFromFoo = NULL;
//mqd_t ExecTimer::mq = (mqd_t)-1;
void FooAnother::createThread(){

    int res = pthread_create(&this->threadFoo,NULL,Run,NULL);
    // check res

}
void FooAnother::cancelThread(){
    pthread_cancel(this->threadFoo);
}

void * FooAnother::Run(void * arg){

    while(true){

        //int mq_send(mqd_t __mqdes,
        //const char *__msg_ptr, size_t __msg_len, unsigned int __msg_prio)

    }


}


FooAnother::FooAnother(){
    this->execTimer.StartUp();
    this->createThread();



}

FooAnother::~FooAnother(){
    this->execTimer.ShutDown();
    this->cancelThread();
}
void FooAnother::doJobFoo2(){
    execTimer.Begin();

    int t = 0 ;

    for (int i = 0; i< 100000;i++){
        t+=i;

    }
    execTimer.End(__func__);
    std::cout << "Tamamen dummy\n";


}
