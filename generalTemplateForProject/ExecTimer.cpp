#include<iostream>
#include<time.h> // for clok_t ,clock()
#include"ExecTimer.h"


using namespace std;

//Private functions 
void ExecTimer::Run(){

}



//Public functions

ExecTimer::ExecTimer(){//I wiil leave this empty


}


int ExecTimer::StartUp(){

    //this will be called not in the function but 
    //in the consructor of the class


     //mq_open seysi
     // constructor zimbirtisini ayarla
     this->funcName = "default";
     this->beginTime=0.0;
     // start thread



     // try-catch yapılablir ama suan oynayamam
     return 0;


}

int ExecTimer::ShutDown(){
    //stop thread and join 
    // mq_close()

    return 0;

}

void ExecTimer::Begin(string fn){

    clock_t beginTime = clock();
    this->beginTime = long(beginTime);
}

void ExecTimer::End(){


}

