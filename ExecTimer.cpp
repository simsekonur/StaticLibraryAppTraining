// cpp
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include"ExecTimer.h"
#include"ExecResult.h"

using namespace std;
const char*ExecTimer::mqName = "mqName";
const char*ExecTimer::threadName = "threadName";
int msgsize = sizeof(myExecResult*);

void* ExecTimer::Run(void * arg){
    while(true){
        myExecResult * results = NULL;
        unsigned int msg_prio;
        int res = mq_receive(mq,reinterpret_cast<char *>(&results),msgsize,&msg_prio);
        if(res ==-1){
        }
        else {
			delete(results);
        }             
    }
}
 
ExecTimer::ExecTimer(){
}

ExecTimer::~ExecTimer(){
	ShutDown();
}

int ExecTimer::StartUp(){
	mq_attr attr2;
    attr2.mq_flags = 0;
    attr2.mq_maxmsg = 100;
    attr2.mq_msgsize = msgsize;
    this->mq = mq_open(mqName,O_CREAT | O_RDWR , 0, &attr2);
    
    if (this->mq != -1)
        cout << "open-mq successful\n";
    else 
        cout << "open-mq is not successful\n";
	
	if (mq_unlink(mqName) == -1)
		return 1;
	
	if (pthread_attr_init(&attr) != 0)
		return 1;
    
    int retVal = pthread_create(&this->newThread,&attr,Run,NULL);
    if (retVal==0)
        cout << "Open-thread is succesfull\n";
    else
        cout << "Open-thread is not succesfull\n";
    
    return 0;

}

int ExecTimer::ShutDown(){
    if (mq_close(mq) == -1)
		return 0;

    if(pthread_cancel(newThread) != -1)
        cout << "thread join successful\n";
    else 
        cout << "thread join is not successful\n";

	return 0;
}

void ExecTimer::Send(){
	myExecResult *results = new myExecResult();
	int res = mq_send(mq, reinterpret_cast<char*>(&results), msgsize, 0);
	if (res == -1) {
	// error
	} else {
	// success
	}
}

void ExecTimer::Wait(){
	if (pthread_join(newThread, 0) != 0) {
		return;
	}
}