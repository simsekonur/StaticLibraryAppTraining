#include<iostream>
#include"Dummy.h"
#include"ExecTimer.h"

Dummy::Dummy(){

    //initialize 

    

    //this->execTimer.startAndSend();

}

void Dummy::doJob(){
    

    //begin
    execTimer.startAndSend(__func__);
    int result =0  ;
    for (int i=0; i< 100000000;i++){

        result +=i;

    }
    execTimer.receiveAndEnd(); 
    //end 

}

void Dummy::doJob2(){

    //begin 


}


//shutdown 