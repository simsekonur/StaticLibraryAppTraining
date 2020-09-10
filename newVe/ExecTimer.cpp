// cpp
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include "ExecTimer.h"


using namespace std;
mqd_t ExecTimer::mq = (mqd_t)-1;
const char*ExecTimer::mqName = "/mqNamee2";
const char*ExecTimer::threadName = "threadName";
int msgsize = sizeof(myExecResult*);


void* ExecTimer::Run(void * arg){
    while(true){
        myExecResult * results = NULL;
        unsigned int msg_prio;
        int res = mq_receive(mq,reinterpret_cast<char *>(&results),msgsize,&msg_prio);
    	if (res == -1) {

    	} else {

    		if (results!= NULL){
    			cout << results->funcName << " " << results->difference<<endl;
    		}


    	}
    }
}
 

ExecTimer::ExecTimer(){}

ExecTimer * ExecTimer::getInstance(){

	static ExecTimer et;

	return &et;
}


ExecTimer::~ExecTimer(){
	ShutDown();
}

int ExecTimer::StartUp(){

	mq_attr attr2;
    
    attr2.mq_flags = 0;
    attr2.mq_maxmsg = 10;
    attr2.mq_msgsize = msgsize;
    this->mq = mq_open(mqName,O_CREAT | O_RDWR , 0, &attr2);
    


	if (mq_unlink(mqName) == -1)
		return 1;
	
	if (pthread_attr_init(&attr) != 0)
		return 1;
    
	//This will create a thread for execTimer class
    int retVal = pthread_create(&this->newThread,&attr,Run,NULL);
    

    return 0;

}

int ExecTimer::ShutDown(){
	mq_close(mq);
	pthread_cancel(newThread);


	return 0;
}

void ExecTimer::Begin(){

	clock_t beginT = clock();
	this->beginTime = (long)beginT;
	//this->setTime(beginT);

}

void ExecTimer::End(const char * fn){
	myExecResult * results = new myExecResult();
	//strcpy(results->funcName,"default");
	//results->difference = 2;
	clock_t endT = clock();
	strcpy(results->funcName,fn);
	results->difference = (long)endT - beginTime;

	int res = mq_send(mq, reinterpret_cast<char*>(&results), msgsize, 0);


}

void ExecTimer::Wait(){
	if (pthread_join(newThread, 0) != 0) {
		return;
	}
}
