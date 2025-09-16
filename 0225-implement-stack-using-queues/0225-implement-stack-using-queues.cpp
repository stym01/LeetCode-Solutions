class MyStack {
public:

    queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int size=q1.size()-1;
        for(int i=0;i<size;i++){
            int a=q1.front();
            q1.pop();
            q1.push(a);
        }
    }
    
    int pop() {
        if(!q1.empty()) {
            int x=q1.front();
            q1.pop();
            return x;
        }
        return -1;
    }
    
    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        return q1.empty()==1;
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