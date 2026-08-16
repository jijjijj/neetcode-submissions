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
            min = std::min(min,
                static_cast<long long>(val));
        }
    }
    
    void pop() {
        const long long top = s.top();

        if (top > 0) {
            min += top;
        }

        s.pop();
    }
    
    int top() {
        if (s.top() >= 0) return min;

        return min - s.top();
    }
    
    int getMin() {
        return min;
    }

private:
    std::stack<long long> s;
    long long min = 0;
};
