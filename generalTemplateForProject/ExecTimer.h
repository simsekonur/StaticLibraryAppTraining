#include<iostream>

class ExecTimer{

    private:
        //begin Time can be of any type 
        long beginTime ;
        std::string funcName;
        void Run();
    public :
        ExecTimer();
        int StartUp();
        int ShutDown();
        void Begin(std::string fn);
        void End();
        


};