#include<iostream>
#include<fcntl.h>
#include<thread>
#include<pthread.h>
#include<unistd.h>
#include<chrono>

#include "ExecTimer.h"

using namespace std;
using namespace std::chrono;



ExecTimer::ExecTimer(){

}
ExecTimer::ExecTimer(string fn){
    this->funcName = fn ;
 
}

void * ExecTimer::startAndSend(string fn){

    this->msqmutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&this->msqmutex);
    this->myMessageQueue.push(fn);
    pthread_mutex_unlock(&this->msqmutex);
    pthread_exit((void *)0);

}

void * ExecTimer::receiveAndEnd(){
    while(true){
        if(this->myMessageQueue.empty()){
            usleep(10000);
            continue;
        }
        pthread_mutex_lock(&this->msqmutex);
        this->funcName = myMessageQueue.front();
        
        
        auto startTime = high_resolution_clock::now();

        thread t1(this->funcName);
        if(t1.joinable()){
            t1.join();
        }

        auto endTime = high_resolution_clock::now();

        auto difference = duration_cast<microseconds>(endTime - startTime);

        long result = difference.count() /10000000;
        this->myMessageQueue.pop();
        cout << "the function name:" << this->funcName << endl ;
        cout << "Execution time:" << result << endl ;
        pthread_mutex_unlock(&msqmutex);




    }
    pthread_exit((void*)0);

}
