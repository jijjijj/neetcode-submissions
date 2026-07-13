class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
         _stack.push_back(val);
        _min.push_back(_min.empty() || _min.back() > val ? val : _min.back());
    }
    
    void pop() {
        _stack.pop_back();
        _min.pop_back();
    }
    
    int top() {
        return _stack.back();
    }
    
    int getMin() {
        return _min.back();
    }

private:
    std::list<int> _stack;
    std::list<int> _min;
};
