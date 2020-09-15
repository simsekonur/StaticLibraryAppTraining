/*
 * Dummy.cpp
 *
 *  Created on: Sep 4, 2020
 *      Author: onur
 */

#include<iostream>
#include"Dummy.h"


Dummy::Dummy(){
	this->execTimer = this->execTimer->getInstance();
    this->execTimer->StartUp();

}

void Dummy::doJob(){
    execTimer->Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer->End(__func__);

}

void Dummy::doJob2(){
    execTimer->Begin();
    int result =0  ;
    for (int i=0; i< 100000000;i++){
        result +=i;
    }
    execTimer->End(__func__);

}

// shutdown
Dummy::~Dummy(){
    this->execTimer->ShutDown();
}

