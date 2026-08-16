class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            min = val;
            s.push(0);
        } else {
            s.push(min - val);
            min = std::min(min, val);
        }
    }
    
    void pop() {
        const int top = s.top();

        if (top > 0) {
            min += top;
        }

        s.pop();
    }
    
    int top() {
        return min - s.top();
    }
    
    int getMin() {
        return min;
    }

private:
    std::stack<int> s;
    int min = 0;
};
