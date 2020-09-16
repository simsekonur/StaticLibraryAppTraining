#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "ExecTimer.h"
#define PORT 8083   /* the port client will be connecting to */

using namespace std;


//There is no global variable in this code
//All of the static variables defined below are declared in the header file of class
mqd_t ExecTimer::mq = (mqd_t)-1;
const char*ExecTimer::mqName = "/mqNamee2";
int ExecTimer::sockfd = -1;



//When creating the thread of execTimer, we are using this function.
void* ExecTimer::Run(void * arg){
    while(true){
        myExecResult * results = NULL;
        unsigned int msg_prio;
		int res ;
		
        int resMq = mq_receive(mq,reinterpret_cast<char *>(&results),sizeof(myExecResult*),&msg_prio);
    	if (resMq == -1 || results==NULL) {
			perror("mq-receive error");
    	} 
		else { // If mq_receive is succcessful

    		if ((res = send(sockfd,results,sizeof(*results),0)) ==-1)
    			perror("Sending error");
    		
    	}
    }
}
 

ExecTimer::ExecTimer(){}

//This method is in here because we don't want to create a seperate execTimer
//object in seperate class 
ExecTimer * ExecTimer::getInstance(){

	static ExecTimer et;

	return &et;
}


ExecTimer::~ExecTimer(){
	ShutDown();
}

int ExecTimer::StartUp(){

	//create a socket
	if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1 ){
		perror("socket");
		exit(1);
	}

	//Initialize the struct member for socket 
	their_addr.sin_family=AF_INET;
	their_addr.sin_port = htons(PORT);
	
	if (connect(sockfd,(struct sockaddr *)&their_addr,sizeof(their_addr)) < 0){
		perror("connect-socket");
		return -1;
	}
	//Initialize the struct member for message queue
	
	mq_attr attr2;
    attr2.mq_flags = 0;
    attr2.mq_maxmsg = 10;
    attr2.mq_msgsize = sizeof(myExecResult*);
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
	close(sockfd);


	return 0;
}

void ExecTimer::Begin(){

	clock_t beginT = clock();
	this->beginTime = (long)beginT;


}

void ExecTimer::End(const char * fn){
	
	myExecResult * results = new myExecResult();
	
	clock_t endT = clock();
	strcpy(results->funcName,fn);
	results->difference = (long)endT - beginTime;

	int res = mq_send(mq, reinterpret_cast<char*>(&results), sizeof(myExecResult*), 0);



}


