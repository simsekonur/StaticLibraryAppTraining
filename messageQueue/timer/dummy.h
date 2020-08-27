#include<iostream>
#include<chrono>
using namespace std;


class Dummy{
    private :
        // starting time 
        chrono::time_point<chrono::high_resolution_clock> startTime ;
        //ending time
        chrono::time_point<chrono::high_resolution_clock> endTime ;

        // function name 
        string functionName ;

    public :
       
        //startTimer --> initializes the thread and internal data  
        //stopTimer --> kill the thread 


        chrono::time_point<chrono::high_resolution_clock> Begin(string funcName);

};