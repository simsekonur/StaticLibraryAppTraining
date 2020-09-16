// header
#ifndef ET
#define ET
#include"ExecResult.h"
#include<pthread.h>
#include<mqueue.h>
#include <arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>


class ExecTimer{
    private:
		long beginTime;
        pthread_t newThread; 
        pthread_attr_t attr;
		static mqd_t mq;
	
		static const char* mqName;
		
		ExecTimer();// we intentionally don't have a constructor
		

		//Variables related to socket
		static int sockfd ;

		struct sockaddr_in their_addr;
        
		
    public:

		~ExecTimer();


        int StartUp();
        int ShutDown();
		void Begin();

		void End(const char * fn);
		
        static void* Run(void * arg);
        static ExecTimer * getInstance();
};
#endif 
