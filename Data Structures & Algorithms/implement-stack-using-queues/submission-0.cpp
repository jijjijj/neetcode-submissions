class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        const int size = q.size();

        for (int i = 1; i < size; ++i) {
            q.push(q.front());
            q.pop();
        }

        const int val = q.front();
        q.pop();

        return val;
    }
    
    int top() {
        const int size = q.size();

        for (int i = 1; i < size; ++i) {
            q.push(q.front());
            q.pop();
        }

        const int val = q.front();
        q.pop();
        q.push(val);

        return val;
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