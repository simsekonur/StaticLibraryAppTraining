#ifndef FOO2_H_
#define FOO2_H_


#include"ExecTimer.h"
typedef void * (*THREADFUNCPTR)(void *);

class Foo{
    private :
        ExecTimer execTimer;
        pthread_t threadFoo; 

        static myExecResult * resultsFromFoo;

    public :
        Foo();
        ~Foo();
        static void  doJobFoo();
        void createThread();
        void cancelThread();
        static void * Run (void * arg );


};

#endif /* FOO2_H_ */
