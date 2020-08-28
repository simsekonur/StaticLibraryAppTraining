#include<iostream>
#include"Dummy.h"


Dummy::Dummy(){

    
    this->execTimer.StartUp();

    

}

void Dummy::doJob(){
    execTimer.Begin(__func__);
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(); 
    

}

void Dummy::doJob2(){
    execTimer.Begin(__func__);
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(); 

}

// shutdown 
Dummy::~Dummy(){
    this->execTimer.ShutDown();
}