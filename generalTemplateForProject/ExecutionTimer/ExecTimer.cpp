#include<iostream>
#include<time.h> // for clok_t ,clock()
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include<thread>
#include"ExecTimer.h"
#include<string.h>

#define QUEUE_NAME  "/test_queue"
#define MAX_SIZE    4096

using namespace std;



//Private function 

void ExecTimer::Run(){
    while(true){

        // mq_receive 
        int retVal = mq_receive(this->mq,(char *)&myExecResult ,sizeof(myExecResult),NULL);
        if (retVal!=-1){
            cout << myExecResult.fn << " : " << myExecResult.execTime<< endl ;
            
        }else {
            
           // cout << retVal << endl ;
           // perror(QUEUE_NAME);
        }
        //consola yazma
        
    }
    
 
}

void*  FakeRun(void * arg){

    ExecTimer execTimer;
 
    execTimer.Run();
    
} 
 


//Public functions

ExecTimer::ExecTimer(){

/***************************
 *       DON'T TOUCH
 * 
 * 
 * *************************/


}


int ExecTimer::StartUp(){

    /*****************************
     * FOR INITIALIZATION PURPOSES
     * in the constructor of the class
     **************************/

     //mq_open seysi
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;
    this->mq = mq_open(QUEUE_NAME,O_CREAT | O_RDWR, 0644, &attr);
    //cout << "Opendan\n" << this->mq;
    //perror(QUEUE_NAME);

    

     // constructors jobs 
            
     // start thread

    int ret = pthread_create(&this->newThread,NULL,FakeRun,NULL);
    
    //returns 0 ,thread is created.

    
     return ret; 


}

int ExecTimer::ShutDown(){
    // mq_close()
    //stop thread and join 
    this->status= mq_close(this->mq);
    pthread_join(this->newThread,NULL);
    pthread_exit(NULL);
    
    
    
    status = mq_unlink("my_queue");
    return 0;

}



/********************
 * THEY WILL BE CALLED IN THE FUNCTION.
 * DON'T PERFORM ANY HARD OPERATION 
 * THAT TAKES SO MUCH TIME.
 * 
 *
*********************/

void ExecTimer::Begin(){


    clock_t beginT = clock();
    this->beginTime = long(beginT);
    
    
}

void ExecTimer::End(const char * fn ){
    
    clock_t endTime = clock();
     
    strcpy(this->funcName,fn);
    strcpy(this->myExecResult.fn,fn);

    this->myExecResult.execTime = long(endTime)- (this->beginTime);
    

    //just for trying,working fine
    //cout << this->myExecResult.fn << " : " << this->myExecResult.execTime<< endl ;
    int retVal = mq_send(this->mq,(const char *)&myExecResult,sizeof(myExecResult),0);
   // cout << "sendden geli,yor" << retVal<<endl ;
   // perror(QUEUE_NAME);
    
}

