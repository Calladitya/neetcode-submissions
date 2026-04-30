#include <stack>
using namespace std;

class MyStack {
private:
    stack<int> obj;   // stack declare kiya

public:
    MyStack() {
        
    }
    
    void push(int x) {
        obj.push(x);
    }
    
    int pop() {
        int topElement = obj.top();  // pehle value store karo
        obj.pop();                   // fir remove karo
        return topElement;           // fir return karo
    }
    
    int top() {
        return obj.top();
    }
    
    bool empty() {
        return obj.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */