#include<iostream>
#include<pthread.h>
#include<thread>
#include<mqueue.h>

class ExecTimer{
    private:
        //Job related to thread
        pthread_t newThread;

        //Job related to message queue
        inline static mqd_t mq ;
        inline static int status ;
        struct mq_attr attr;

        //Job related to execTimer
        long beginTime;

    public:
        ExecTimer();
        int StartUp();
        int ShutDown();
        void Begin();
        void End(const char * fn);
        static void* Run(void * arg);

};