#include<iostream>
#include<thread> 
#include<chrono>

using namespace std;

void run(int count){
    while(count > 0){
        cout << "I'm trying!\n";
        count -=1 ;
    }
    std::this_thread::sleep_for(chrono::seconds(3));
}


int main(void){
    std::thread t1(run,10);
    cout << "Now, I'm in the main...\n";

    //When I say, t1.join what happens?
    t1.join();
    cout << "I finished the thread jobs\n";
    cout << "Done the main!\n";


    

}