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
#define MAX_SIZE    1024

using namespace std;



//Private function 

void ExecTimer::Run(){
    while(true){

        // mq_receive 
        int retVal = mq_receive(this->mq,this->myExecResult.fn ,sizeof(this->myExecResult.fn),NULL);
        if (retVal!= -1){
            cout << myExecResult.fn << " : " << myExecResult.execTime<< endl ;
            
        }else {


        }
        //consola yazma
        
    }
    
 
}

void*  FakeRun(void * arg){

    ExecTimer execTimer;
    execTimer.StartUp();
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
    this->mq = mq_open(QUEUE_NAME,O_CREAT | O_RDONLY, 0644, &attr);
    

     // constructors jobs 
     strcpy(this->funcName,"default");
     this->beginTime= 0.0;
     strcpy(this->myExecResult.fn,"default");
     this->myExecResult.execTime =0.0;        
     // start thread

    int ret = pthread_create(&this->newThread,NULL,FakeRun,NULL);
    
    //returns 0 ,thread is created.

    
     return ret; 


}

int ExecTimer::ShutDown(){
    //stop thread and join 
    
    pthread_join(this->newThread,NULL);
    pthread_exit(NULL);
    
    // mq_close()
    this->status= mq_close(this->mq);
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
 
}

