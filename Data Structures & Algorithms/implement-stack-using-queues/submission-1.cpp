class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        const int size = q.size();
        q.push(x);
        for (int i = size; i > 0; --i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        const int val = q.front();
        q.pop();

        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

private:
    std::queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */