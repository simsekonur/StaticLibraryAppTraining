#include"ExecutionTimer.h"
#include<thread>
#include<chrono> 

using namespace std;
using namespace std::chrono;

ExecutionTimer::ExecutionTimer(){

    this->functionName = "default";

}

chrono::time_point<chrono::high_resolution_clock> ExecutionTimer::End(){
    return high_resolution_clock::now();

}

int ExecutionTimer::findExecutionTime(const string funcName){
    
}     

void ExecutionTimer::Begin(const char * funcName){
    this->startTime = high_resolution_clock::now();
    pthread_t thr;

    pthread_create(&thr,NULL,(void *)funcName,NULL);
    this->endTime = high_resolution_clock::now();

}

