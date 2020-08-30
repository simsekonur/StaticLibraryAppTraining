#include<iostream>
#include<time.h> // for clok_t ,clock()
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include<thread>
#include"ExecTimer.h"


using namespace std;


//Private function and struct 

void ExecTimer::Run(){
    while(true){

        // mq_receive seysi

        //consola yazma
    }


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
     * in the consructor of the class
     **************************/

     //mq_open seysi
     
     this->mq = mq_open ("my_queue", O_CREAT|O_RDWR);
     

     // constructors jobs 
     this->funcName = "default";
     this->beginTime= 0.0;
     
     // start thread

     
     
     




     // try-catch yapılablir ama suan oynayamam
     return 0;


}

int ExecTimer::ShutDown(){
    //stop thread and join 
    
   
    
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

void ExecTimer::End(string fn ){
    clock_t endTime = clock();
    
  

    this->myExecResult.fn = fn ;
    this->myExecResult.execTime = long(endTime)- (this->beginTime);
    

    //just for trying,working fine
    //cout << myExecResult.fn << " : " << myExecResult.execTime<< endl ;
    
    

    //values are true 
}

