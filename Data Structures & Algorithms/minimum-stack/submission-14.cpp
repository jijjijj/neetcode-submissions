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
            min = std::min(min, static_cast<long>(val));
        }
    }
    
    void pop() {
        const long top = s.top();

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
    std::stack<long> s;
    long min = 0;
};
