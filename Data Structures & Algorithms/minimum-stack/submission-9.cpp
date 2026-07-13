class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            min = val;
            s.push(val);
        } else {
            s.push(val - min);
            min = std::min(val, min);
        }
    }
    
    void pop() {
        if (s.top() < 0) min -= s.top();
        s.pop();
    }
    
    int top() {
        if (s.size() == 1) return s.top();

        return s.top() > 0 ? s.top() + min : min;
    }
    
    int getMin() {
        return min;
    }

private:
    std::stack<int> s;
    int min = 0;
};
