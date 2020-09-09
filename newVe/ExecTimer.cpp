// cpp
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include "ExecTimer.h"


using namespace std;
mqd_t ExecTimer::mq = (mqd_t)-1;
const char*ExecTimer::mqName = "/mqNamee1";
const char*ExecTimer::threadName = "threadName";
int msgsize = sizeof(myExecResult*);


void* ExecTimer::Run(void * arg){
    while(true){
        myExecResult * results = NULL;
        unsigned int msg_prio;
        int res = mq_receive(mq,reinterpret_cast<char *>(&results),msgsize,&msg_prio);
    	if (res == -1) {
    		//cout << "mq_receive not successful\n";
    	} else {
    	//	cout << "mq_receive successful\n";
    		if (results!= NULL){
    			cout << results->funcName << " " << results->difference<<endl;
    		}

//    		delete(results);
    	}
    }
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
    
    if (this->mq != -1)
        cout << "open-mq successful\n";
    else {
        cout << "open-mq is not successful";
        return 0;
    }

	if (mq_unlink(mqName) == -1)
		return 1;
	
	if (pthread_attr_init(&attr) != 0)
		return 1;
    
	//This will create a thread for execTimer class
    int retVal = pthread_create(&this->newThread,&attr,Run,NULL);
    if (retVal==0)
        cout << "Open-thread is succesfull\n";
    else
        cout << "Open-thread is not succesfull\n";
    
    return 0;

}

int ExecTimer::ShutDown(){
    if (mq_close(mq) == -1)
        cout << "mq_closesuccessful\n";
    else
        cout << "mq_close is not successful\n";

    if(pthread_cancel(newThread) != -1)
        cout << "thread cancel successful\n";
    else 
        cout << "thread cancel is not successful\n";

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
	if (res == -1) {
		cout << "mq_send not successful\n";
	} else {
		cout << "mq_send successful\n";
	}

}

void ExecTimer::Wait(){
	if (pthread_join(newThread, 0) != 0) {
		return;
	}
}
