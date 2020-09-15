#ifndef FOOANOTHER_H_
#define FOOANOTHER_H_

#include"ExecTimer.h"
class FooAnother {
private :
        ExecTimer * execTimer2;
        pthread_t threadFoo2;

    public :
        FooAnother();
        ~FooAnother();
        void doJobFoo2();

        void doJobFromAnother();
        static void * Run(void *);

        void wait();

};

#endif /* FOOANOTHER_H_ */
