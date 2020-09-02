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
    std::cout << "mainDe basladik\n";
    Dummy dummy;
    dummy.doJob();
    dummy.doJob2(); 
    dummy.doJob3();

}