#include<iostream>

#include<queue>

using namespace std;

void print(queue<int> que){

    while(!que.empty()){
        
        cout << que.front()<< " " ;
        que.pop();

    }

}

int main(void){

    queue<int> que;

    que.push(2);
    que.push(4);
    que.push(6);
    print(que);
}