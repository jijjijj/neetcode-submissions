class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        in.push(x);
        while (!out.empty()) {
            in.push(out.front());
            out.pop();
        }
        std::swap(out, in);
    }
    
    int pop() {
        const int val = out.front();
        out.pop();

        return val;
    }
    
    int top() {
        return out.front();
    }
    
    bool empty() {
        return out.empty();
    }

private:
    std::queue<int> in;
    std::queue<int> out;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */