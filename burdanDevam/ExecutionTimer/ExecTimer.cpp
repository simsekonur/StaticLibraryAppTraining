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
    cout << "Run'a geldi " << key << endl ;
    while(1){
        if(key){// in only this condition,mq_receive
            cout << "Loop un icindeki ife girdi\n";
            int retVal = mq_receive(this->mq,(char *)&this->results ,sizeof(this->results),NULL);
            if (retVal!=-1){
                cout << this->results.fn << " : " << this->results.execTime<< endl ;
            }else {
            
            
               //perror(QUEUE_NAME);
            }
        }

        // mq_receive 

        
    }
    
    
 
}

void*  FakeRun(void * arg){

    ExecTimer execTimer;
 
    execTimer.Run();
    return NULL;
    
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
    cout << "Start up a geldi\n";
     //mq_open seysi
    attr.mq_flags = 0;
    attr.mq_maxmsg = 129;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;
    this->mq = mq_open(QUEUE_NAME,O_CREAT | O_RDWR , 0644, &attr);
    cout << "mq_opendan" << this->mq<<endl;
    //perror(QUEUE_NAME);

     // constructors jobs 
     this->key = false ;
            
     // start thread

    int ret = pthread_create(&this->newThread,NULL,FakeRun,NULL);
    
    //returns 0 ,thread is created.

    cout << "Start up tan cikiyor\n";
    return ret; 


}

int ExecTimer::ShutDown(){
    // mq_close()
    //stop thread and join 
    
    //this->status= mq_close(this->mq);
    pthread_join(this->newThread,NULL);
    pthread_exit(NULL);
    
    
    
    //status = mq_unlink(QUEUE_NAME);
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
    cout << "Begine geldi\n";

    clock_t beginT = clock();
    this->beginTime = long(beginT);
    cout << "Beginden cikti\n";
    
}

void ExecTimer::End(const char * fn ){
    cout << "Ende geldi\n";
    clock_t endTime = clock();
     
    
    strcpy(this->funcName,fn);
    strcpy(results.fn,fn);

    results.execTime = long(endTime)- (this->beginTime);
    

    //just for trying,working fine
   // cout << results.fn << " : " << results.execTime<< endl ;
    cout << "Sendi deniycez\n";
    const char * tmp = reinterpret_cast<const char*>(&results);
    int retVal = mq_send(this->mq,tmp,sizeof(results),0);
    cout << "Sendden cik artik\n";
    this->key = true ;
    

    
    cout << "sendden ciktik" << retVal<<endl ;
    perror(QUEUE_NAME);
    cout << "Endden cikiyor\n";
   
    
}

