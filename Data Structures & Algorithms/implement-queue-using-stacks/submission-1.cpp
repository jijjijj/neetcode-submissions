class MyQueue {
public:
    MyQueue() {
        
    }
    
    // [1, 2, 3] - [1, 2, 3]
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        peek();
        const int ans = s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    std::stack<int> s1;
    std::stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */