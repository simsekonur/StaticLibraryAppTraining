#ifndef FOO2_H_
#define FOO2_H_


#include"ExecTimer.h"


class Foo{
    private :
        ExecTimer *execTimer;
        pthread_t threadFoo; 



    public :
        Foo();
        ~Foo();

        void  doJobFoo();
        void doJobFromFoo();


        static void * Run (void * arg );
        void wait();



};

#endif /* FOO2_H_ */
