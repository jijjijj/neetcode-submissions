class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min = s.empty() ? val : s.top().second;

        s.push(std::make_pair(val, std::min(min, val)));
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
    std::stack<std::pair<int, int>> s; // element, minimum
};
