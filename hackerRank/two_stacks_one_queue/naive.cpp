#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stackNewestOnTop;
        stack<int> stackOldestOnTop;

        //O(1)
        void push(int x) {
            stackNewestOnTop.push(x);           
        }

        //O(2*N)
        void pop() {
            newest_to_oldest();
            stackOldestOnTop.pop();
            oldest_to_newest(); 
        }

        //O(2*N)
        int front() {
            newest_to_oldest();
            int ret = stackOldestOnTop.top();
            oldest_to_newest();
            return ret;
        }

        //O(N)
        void newest_to_oldest(){
            while(!stackNewestOnTop.empty()){
                stackOldestOnTop.push(stackNewestOnTop.top());
                stackNewestOnTop.pop();
            }
        }

        //O(N)
        void oldest_to_newest(){
            while(!stackOldestOnTop.empty()){
                stackNewestOnTop.push(stackOldestOnTop.top());
                stackOldestOnTop.pop();
            }
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
