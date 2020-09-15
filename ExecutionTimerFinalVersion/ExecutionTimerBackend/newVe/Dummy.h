/*
 * Dummy.h
 *
 *  Created on: Sep 4, 2020
 *      Author: onur
 */

#ifndef DUMMY_H_
#define DUMMY_H_

#include"ExecTimer.h"

class Dummy{
    private:
        int i;
        ExecTimer *execTimer;
    public:
        Dummy();
        ~Dummy();
        void doJob();
        void doJob2();



};
#endif /* DUMMY_H_ */
