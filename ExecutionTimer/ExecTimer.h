#include<iostream>
#include<thread>

class ExecTimer{

    private:
        //Job related to execution time result 
        
        struct ExecResult {
            std::string fn ; // function name 
            long execTime; // the time difference


        }myExecResult;

        //Job related to thread
        std::thread  t1;
        
        

        //Job related to message queue
        int status;
        int mq;

        /////////////////////////
        //begin time can be of any type 
        //Job related to execution timer         
        long beginTime;
        std::string funcName;


        void Run();

    public :
        ExecTimer();//it will be empty 
        int StartUp();
        int ShutDown();
        void Begin();
        void End(std::string fn);
        
        


};