// header
#ifndef ET
#define ET
#include<pthread.h>
#include<mqueue.h>

class ExecTimer{
    private:
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
		void Send();
		void Wait();
        static void* Run(void * arg);
};
#endif 
