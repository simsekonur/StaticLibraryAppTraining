#include<iostream>
#include<pthread.h>
#include<thread>
#include<mqueue.h>


class ExecTimer{

    private:
        //Job related to execution time result 
        
        typedef struct ExecResult {
            char fn[128] ; // function name 
            long execTime; // the time difference


        }myExecResult;

        myExecResult *results; 
        bool key ;

        //Job related to thread
        pthread_t newThread;
        
        

        //Job related to message queue
        int status;
        mqd_t mq1;
        
        key_t my_key;
        int msg_id;
       

        struct mq_attr attr;  

        /////////////////////////
        //begin time can be of any type 
        //Job related to execution timer         
        long beginTime;
        char funcName[128];


        

    public :
        ExecTimer();//it will be empty 
        int StartUp();
        int ShutDown();
        void Begin();
        void End(const char* fn);
        void Run();
        
        
        


};