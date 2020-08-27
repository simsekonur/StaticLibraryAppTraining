#include<iostream>
#include<chrono>

using namespace std;



class ExecutionTimer{
    private :
        // starting time 
        chrono::time_point<chrono::high_resolution_clock> startTime ;
        //ending time
        chrono::time_point<chrono::high_resolution_clock> endTime ;

        // function name 
        string functionName ;

    public :
        ExecutionTimer(); // default consructor 
        ExecutionTimer(chrono::time_point<chrono::high_resolution_clock>,chrono::time_point<chrono::high_resolution_clock>,string); // consructor
        
        //startTimer --> initializes the thread and internal data  
        //stopTimer --> kill the thread 


        void Begin(const char *funcName);
        chrono::time_point<chrono::high_resolution_clock> End();

        //Execution time in terms of second 
        int findExecutionTime(const string funcName);
      
};


