#include<iostream>
#include<time.h> // for clok_t ,clock()
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include<thread>
#include<string.h>


using namespace std;
struct ExecResult {

    long id;
    char  funcName[128] ;
}myExecResult;
int main(void){
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 129;
    attr.mq_msgsize = 1024;
    attr.mq_curmsgs = 0;

    mqd_t mq = mq_open("/mq",O_RDWR | O_CREAT, 0666, &attr);
    // returns -1 on error 

    if(mq!=-1){
        cout << "Open is  succesfull\n";

    }
    else {
        cout << "Open is not   succesfull\n";
    }
    
    strcpy(myExecResult.funcName,"default");

    myExecResult.id = 2;

    const char * tmp = reinterpret_cast<const char *>(&myExecResult);

    int n = mq_send(mq,tmp,sizeof(myExecResult),0);
   
    if(n==0){
        cout << "Send is succesfull\n";

    }
    else {
        cout << "Send is not succesfull\n";
    }


    int recVal = mq_receive(mq,(char *)&myExecResult,sizeof(myExecResult),NULL);
    cout << recVal;
    perror("/mq");
    
    

}
