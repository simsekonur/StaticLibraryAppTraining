// cpp
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include "ExecTimer.h"
#include "ExecResult.h"
#define QUEUENAME "/mqName6"
using namespace std;

mqd_t ExecTimer::mq = (mqd_t)-1;
//const char * ExecTimer::mqName = "/mqName5";

void* ExecTimer::Run(void * arg){
    while(true){
		myExecResult * results = NULL;
		unsigned int msg_prio;


		int res = mq_receive(mq,reinterpret_cast<char *>(&results),sizeof(results),&msg_prio);
		if (res == -1) {

    		//cout << "mq_receive not successful\n";
    	} else {


    		cout << results->funcName << " " << results->difference<<endl;
//    		delete(results);
    	}

	}
}
 


ExecTimer::~ExecTimer(){
	ShutDown();
}

int ExecTimer::StartUp(){

	mq_attr attr2;
	attr2.mq_flags =0 ;
	attr2.mq_msgsize = sizeof(myExecResult *);
	attr2.mq_maxmsg = 10;
	this->mq = mq_open(QUEUENAME ,O_CREAT|O_RDWR,0,&attr2);

	int res = pthread_create(&this->newThread,NULL,Run,NULL);
	return res;

}

int ExecTimer::ShutDown(){
	int res1=mq_close(this->mq);
	int res2=pthread_cancel(this->newThread);

	return res2;
}
void ExecTimer::Begin(){
	clock_t beginT = clock();
	this->beginTime = (long)beginT;

}

void ExecTimer::End(const char * fn){
	clock_t endT = clock();

	myExecResult * results = new myExecResult();
	strcpy(results->funcName,fn);
	results->difference = (long)endT -this->beginTime;

	int res = mq_send(this->mq,reinterpret_cast<char *>(&results),sizeof(results),0);


	
}

void ExecTimer::Wait(){
	if (pthread_join(newThread, 0) != 0) {
		return;
	}
}
