#include<iostream>
#include<pthread.h>
#include<thread>
#include<mqueue.h>

class ExecTimer{
    private:
        //It will the job related to 
        //result of the exec timer
        typedef struct ExecResult{
            char funcName[128];
            long execTime;
            
        }myExecResult;
        myExecResult * results;

        //Job related to thread
        pthread_t newThread;

        //Job related to message queue
        key_t myKey1;
        int messageId1;
        key_t myKey2;
        int messageId2;
        bool controlLoop;
        
        //Job related to execTimer
        long beginTime;

        
    public:
        ExecTimer();
        int StartUp();
        int ShutDown();
        void Begin();
        void End(const char * fn);
        void Run();




};