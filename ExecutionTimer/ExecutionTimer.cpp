#include"ExecutionTimer.h"

using namespace std;

ExecutionTimer::ExecutionTimer(){

    this->functionName = "default";

}

chrono::time_point<chrono::high_resolution_clock> ExecutionTimer::End(){
    return chrono::high_resolution_clock::now();

}

