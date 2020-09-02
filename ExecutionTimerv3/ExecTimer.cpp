#include<iostream>
#include<time.h> // for clok_t ,clock()
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<thread>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#include"ExecTimer.h"



#define QUEUE_NAME  "/test_queue"
using namespace std;

//Private functions
void ExecTimer::Run(){
    cout << "It enters run\n";
    while(true){
        //msgrcv
        //cout 
        
       // cout << "We will try receive\n";
        int retValRec = msgrcv(this->messageId2,(void *)this->results,sizeof((void *)this->results),(long)1,0);
        //Invalid argument 
        if(retValRec!=-1)
            cout << "Receive is succesful\n";
        //else 
            //perror("ReceiveError");
            //Invalid argument 
    }
    cout << "It exits run\n";


}
void*  FakeRun(void * arg){

    ExecTimer execTimer;
 
    execTimer.Run();
    return NULL;
    
} 
 

//public functions

ExecTimer::ExecTimer(){
    

}

int ExecTimer::StartUp(){
    cout << "It enters start up\n";
    this->controlLoop = false;
    //Sendci kardes
    this->myKey1 = ftok("progfile",65);
    this->messageId1 = msgget(this->myKey1,0666 | IPC_CREAT);
    //Receive ci kardes
    this->myKey2 = ftok("progfie",66);
    this->messageId2 = msgget(this->myKey1,0666 | IPC_CREAT);
    
    if (messageId1 >=0)
        cout << "open-mq successful\n";
    else 
        cout << "open-mq is not successful\n";
    
    int retVal = pthread_create(&this->newThread,NULL,FakeRun,NULL);
    if (retVal==0)
        cout << "Open-thread is succesfull\n";
    else
        cout << "Open-thread is not succesfull\n";
    
    cout << "It exits start up\n";

}
int ExecTimer::ShutDown(){
    //mq_close 
    //join and stop thread
    cout << "It enters ShutDown\n";
    //msgctl(this->messageId1,IPC_RMID, NULL);
    int retVal=pthread_join(this->newThread,NULL);
    if(retVal==0)
        cout << "thread join successful\n";
    else 
        cout << "thread join is not successful\n";
    pthread_exit(NULL);
    cout << "It exits ShutDown\n";

}

void ExecTimer::Begin(){
    cout << "It enters begin\n";
    clock_t beginT = clock();
    this->beginTime = (long)beginT;
    cout << "It exits begin\n";

}
void ExecTimer::End(const char * fn){
    cout << "It enters end\n";
    clock_t endTime = clock();
    this->results = new myExecResult();
    strcpy(this->results->funcName,fn);
    this->results->execTime = (long)endTime -(this->beginTime);
    
    //working fine
    //cout << this->results->funcName << " : " << this->results->execTime << endl;

    //I am going to send my structure by using a message queue
    //to the receiver(msgsnd) we are sending a POINTER to a struct
    

    cout << "We will try send!\n";
    int sendVal = msgsnd(this->messageId1,(const void *)this->results,sizeof(this->results),0);
    if(sendVal==0){
        cout << "send is successful\n";
        this->controlLoop = true;
    }
        
    else 
        cout << "send is not succesful\n";
    cout << "Send is finished\n";
    cout << "It exits end\n";


}




