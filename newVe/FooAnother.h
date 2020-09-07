#ifndef FOOANOTHER_H_
#define FOOANOTHER_H_

#include"ExecTimer.h"
class FooAnother {
private :
        ExecTimer execTimer;
        pthread_t threadFoo;

        static myExecResult * resultsFromFoo;

    public :
        FooAnother();
        ~FooAnother();
        void doJobFoo2();
        void createThread();
        void cancelThread();
        static void * Run(void *);


};

#endif /* FOOANOTHER_H_ */
