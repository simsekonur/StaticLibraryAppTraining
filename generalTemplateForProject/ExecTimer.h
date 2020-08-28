#include<iostream>

class ExecTimer{

    private:
        //begin Time can be of any type 
        long beginTime ;
        std::string funcName;
        void Run();
    public :
        ExecTimer();//it will be empty 
        int StartUp();
        int ShutDown();
        void Begin(std::string fn);
        void End();
        


};
