class MyQueue {
public:

    stack<int>inp;
    stack<int>out;

    MyQueue() {
        
    }
    
    void push(int x) {
        
        inp.push(x);

    }
    
    int pop() {
        if(out.empty()){
            //inp to out
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
        }
        int x=out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        if(out.empty()){
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return (inp.empty()&& out.empty())==1;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */