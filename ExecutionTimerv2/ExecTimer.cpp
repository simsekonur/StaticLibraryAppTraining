#include<iostream>
#include<time.h> // for clok_t ,clock()
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include<thread>
#include"ExecTimer.h"
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

#define QUEUE_NAME  "/test_queue"

using namespace std;



//Private function 

void ExecTimer::Run(){
    cout << "Run'a geldi " << key << endl ;
    while(true){
       
        //cout << "Loop un icindeki ife girdi\n";
        
        void * ptr = reinterpret_cast<void *>(this->results);
        cout << "receive deniycez\n";
        int retVal = msgrcv(this->msg_id,ptr,sizeof(ptr),1,0);
       // cout << "Receive :"<< retVal<< endl ;
        if (retVal<0){
            //usleep(10000);
           // perror(QUEUE_NAME);
           // continue;
        }else {
            cout << this->results->fn << " : " << this->results->execTime<< endl ;

            
        }
        
            
        // mq_receive 
        
        

   
    }
    cout << "Rundan cikiyor\n";
 
}

void*  FakeRun(void * arg){

    ExecTimer execTimer;
 
    execTimer.Run();
    return NULL;
    
} 
 


//Public functions

ExecTimer::ExecTimer(){}



int ExecTimer::StartUp(){

    /*****************************
     * FOR INITIALIZATION PURPOSES
     * in the constructor of the class
     **************************/
    cout << "Start up a geldi\n";
     //mq_open seysi
    this->my_key = ftok("progfile",65);
    this->msg_id = msgget(my_key,0666|IPC_CREAT|O_NONBLOCK);

   
    cout << "mq_opendan" << this->msg_id << endl;
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
    cout << "shut down'a geldi\n";
    
    
    //this->status= mq_close(this->mq);
    pthread_join(this->newThread,NULL);
    pthread_exit(NULL);
    msgctl(this->msg_id,IPC_RMID,NULL);
    
    
    
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
    strcpy(results->fn,fn);

    results->execTime = long(endTime)- (this->beginTime);
    

    //just for trying,working fine
    //cout << results->fn << " : " << results->execTime<< endl ;
    cout << "Sendi deniycez\n";
    const void * tmp = reinterpret_cast<const void *>(this->results);
    cout << "cast islemi bsarili\n";

    int retVal = msgsnd(this->msg_id,tmp,sizeof(tmp),0);
    cout << "Sendden cik artik\n";
    this->key = true ;
    
    
    
    cout << "sendden ciktik" << retVal<<endl ;
    
    cout << "Endden cikiyor\n";
   
    
}

