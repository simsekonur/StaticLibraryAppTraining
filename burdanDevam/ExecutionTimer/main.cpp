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
    cout << "mainDe basladik\n";
    Dummy dummy;
    dummy.doJob();
    dummy.doJob2();

}