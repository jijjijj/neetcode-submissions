class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push({ val, val });
        } else {
            s.push({ val, std::min(val, s.top().second ) });
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }

private:
    std::stack<std::pair<int, int>> s; // val, min
};
