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
#include"ExecResult.h"


#define QUEUE_NAME  "/test_queue"
using namespace std;

//Private functions
void* ExecTimer::Run(void * arg){
    cout << "It enters run\n";
    while(true){
        //mq_receive
        //cout  

        myExecResult * results = NULL;
        unsigned int msg_prio;

        int res = mq_receive(mq,reinterpret_cast<char *>(&results),4,&msg_prio);
        if(res ==-1){
            
        }
        else {
            cout << "Receive successful\n";
        }
          
           
        
       
    }
    cout << "It exits run\n";


}

 

//public functions

ExecTimer::ExecTimer(){
    

}

int ExecTimer::StartUp(){
    cout << "It enters start up\n";
    attr.mq_flags = 0;
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = 4;
    attr.mq_curmsgs = 0;
    this->mq = mq_open(QUEUE_NAME,O_CREAT | O_RDWR , 0644, &attr);
    
    if (this->mq != -1)
        cout << "open-mq successful\n";
    else 
        cout << "open-mq is not successful\n";
    
    int retVal = pthread_create(&this->newThread,NULL,Run,NULL);
    if (retVal==0)
        cout << "Open-thread is succesfull\n";
    else
        cout << "Open-thread is not succesfull\n";
    
    cout << "It exits start up\n";
    return 0;

}
int ExecTimer::ShutDown(){
    //mq_close 
    //join and stop thread
    cout << "It enters ShutDown\n";
    //msgctl(this->messageId1,IPC_RMID, NULL);
    this->status = mq_close(mq);
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
    myExecResult * results  = new myExecResult();
    strcpy(results->funcName,fn);
    results->execTime = (long)endTime -(this->beginTime);
    
    //working fine
    //cout << this->results->funcName << " : " << this->results->execTime << endl;

    //I am going to send my structure by using a message queue
    //to the receiver(msgsnd) we are sending a POINTER to a struct
    

    cout << "We will try send!\n";
    // mq_send 
    int res = mq_send(mq,reinterpret_cast<const char *>(&results),4,0);
    if(res==-1)
        cout << "send is not succesful\n";
    else 
        cout << "send is succesful\n";

    cout << "Send is finished\n";
    cout << "It exits end\n";


}




