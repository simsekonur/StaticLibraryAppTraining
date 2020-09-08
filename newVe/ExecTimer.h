// header
#ifndef ET
#define ET
#include"ExecResult.h"
#include<pthread.h>
#include<mqueue.h>



class ExecTimer{
    private:
		long beginTime;
        pthread_t newThread; 
        pthread_attr_t attr;
		static mqd_t mq;
		static size_t size;

		static const char* mqName;
		static const char* threadName;
        
		
    public:
//        ExecTimer();
		~ExecTimer();

        int StartUp();
        int ShutDown();
		void Begin();

		void End(const char * fn);
		void Wait();
        static void* Run(void * arg);
};
#endif 
