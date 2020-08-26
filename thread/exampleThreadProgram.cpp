#include<iostream>
#include<thread>
#include<chrono> // jobs related to timing 

using namespace std;
using namespace std::chrono;

typedef long long int ull;

//I'm gonna create two functions 
//that takes so many time to execute
// and test them with and without thread


//I'm gonna create two funcitons that 
// also take a pointer as an argument

void oddSum(ull start, ull end, ull * oddSumm){

    for (ull i = start ; i< end ;i++){
        if ((i %2) == 1){
            *(oddSumm) += i ;
        }
    }

}

void evenSum(ull start, ull end, ull * evenSum){

    for (ull i = start ; i< end ;i++){
        if((i%2)==0){
            *(evenSum)+= i;
        }
    }   

}
//It will take so many time to execute these functions.
//Execution will come to oddSum AND THEN even sum.
// And the time it takes for program to execute will be the 
// summatiton.



int main (){

    ull start =0;
    ull end = 1900000000;
    ull oddSummation =0;
    ull evenSummation =0;

    //Take the time before starting 
    auto startTime = high_resolution_clock::now();
    // Call the function to understand how much it passed ?
    oddSum(start,end,&(oddSummation));
    evenSum(start,end,&(evenSummation));
    auto endTime = high_resolution_clock::now();
    auto howMuch1 = duration_cast<microseconds>(endTime - startTime);
    cout << "Without a thread: "<< howMuch1.count()/ 10000000 << endl ;


    //Preparation with thread version :
    cout << "Preparation with thread version :" << endl ;
    oddSummation = 0;evenSummation=0;

    //What happens if we use thread ?
    // Four lines of code 
    // creating thread  for each functions 
    // joining them to our thread
    auto startTime2 = high_resolution_clock::now();

    thread t1(oddSum,start,end,&(oddSummation));
    thread t2(evenSum,start,end,&(evenSummation));
    

    t1.join();
    t2.join();

    auto endTime2 = high_resolution_clock::now();
    auto howMuch2 = duration_cast<microseconds>(endTime2 - startTime2);
    cout << "With a thread: "<< howMuch2.count()/ 10000000 << endl ;




}
