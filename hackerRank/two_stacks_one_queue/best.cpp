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
        stack<int> insert_stack;
        stack<int> pop_stack;  

        //O(1) 
        void push(int x) {
            insert_stack.push(x);
        }

        //O(N), Θ(1)
        void pop() {
            prepare_top();
            pop_stack.pop();
        }

        //O(N), Θ(1)
        int front() {
            prepare_top();
            return pop_stack.top();
        }

        //O(N), Θ(1)
        void prepare_top(){
            if(pop_stack.empty()){
                while(!insert_stack.empty()){
                    pop_stack.push(insert_stack.top());
                    insert_stack.pop();
                }
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
