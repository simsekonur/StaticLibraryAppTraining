/*
 * Dummy.cpp
 *
 *  Created on: Sep 4, 2020
 *      Author: onur
 */

#include<iostream>
#include"Dummy.h"


Dummy::Dummy(){

    this->execTimer.StartUp();

}

void Dummy::doJob(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}

void Dummy::doJob2(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}
void Dummy::doJob3(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}
void Dummy::doJob4(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}
void Dummy::doJob5(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}
void Dummy::doJob6(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}
void Dummy::doJob7(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}
void Dummy::doJob8(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}
void Dummy::doJob9(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}
void Dummy::doJob10(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}
void Dummy::doJob11(){
    execTimer.Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer.End(__func__);

}


// shutdown
Dummy::~Dummy(){
    this->execTimer.ShutDown();
}

