#include<iostream>
#include<queue>
#include<pthread.h>

using namespace std;

class ExecTimer{
    private :
        
            long mtype ;// All of the msgsnd msgrcv functions are 
                        // working with 
             
            string funcName; // important 
            pthread_mutex_t msqmutex; // mutex for initialization
            queue<string> myMessageQueue; // important and reuqired
        

    public :
        ExecTimer();
        ExecTimer(string fn);
        
        void * startAndSend(string fn);
        void * receiveAndEnd();






};