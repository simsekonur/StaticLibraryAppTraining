#ifndef FOOANOTHER_H_
#define FOOANOTHER_H_

#include"ExecTimer.h"
class FooAnother {
private :
        ExecTimer execTimer;
        pthread_t threadFoo2;

    public :
        FooAnother();
        ~FooAnother();
        void doJobFoo2();
        void createThread();
        void cancelThread();
        void doJobFromAnother();
        static void * Run(void *);

        void wait();

};

#endif /* FOOANOTHER_H_ */
