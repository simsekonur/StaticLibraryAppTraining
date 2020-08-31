#include<iostream>
#include"Dummy.cpp"

/**********************
 * 
 * Compilation : g++ main.cpp -lrt -lpthread
 * 
 * 
 * 
 * 
 * ************************/

int main(void){

    Dummy dummy;
    dummy.doJob();
    dummy.doJob2();

}