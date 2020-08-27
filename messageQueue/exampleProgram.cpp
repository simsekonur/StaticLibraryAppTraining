#include<iostream>
#include<fcntl.h>
#include<pthread.h>
#include<queue>
#include<unistd.h>

using namespace std;

pthread_mutex_t msqmutex = PTHREAD_MUTEX_INITIALIZER;

queue<string> myMessageQueue;

int count =0 ;
int inTotal =0 ;
//I'm gonna create two functions for sending and 
//receiving the messages.

void* sender(void *arg){
    string mes;
    cout << "Sendera geldi!\n";
    while(true){ // We want to repeatly take message from user
        cin >> mes;
        pthread_mutex_lock(&msqmutex);
        myMessageQueue.push(mes);
        
        pthread_mutex_unlock(&msqmutex);


    }
    //pthread_exit((void *)0);
    cout << "sender dan cıkıyor\n";

}


void* receiver (void * arg){
    string mes;
    while(true){
        //I don't want to miss anything
        //wait a little bit
        //Wait for 0.001 second

        if (myMessageQueue.empty()){
            usleep(10000);
            // wait for 0.001 second 
            // and then check for something 
            // in the queue
            continue;

        }


        pthread_mutex_lock(&msqmutex);
        
        //Receiver takes whatever comes from sender
        mes = myMessageQueue.front();
        myMessageQueue.pop();
        cout << "Value you entered: " << mes << endl;
        
        pthread_mutex_unlock(&msqmutex);
    }
    cout << "Job is finished!\n";
    //pthread_exit((void *)0);

    
}
//We have two functions 
//In the main, I'm gonna create two threads
//for these two functions

int main(void){
    pthread_t thr;
    if (pthread_create(&thr,NULL,receiver,NULL)||
        pthread_create(&thr,NULL,sender,NULL)
         ){
             cout << "Can not make a thread!";
             exit(1);
         }
    cout << "I'am jumping out of the main.\n";

    pthread_exit((void *)0);
}