class MinStack {
private:
    struct Val {
        int val{};
        int min{};
    };

public:
    MinStack() {
        
    }
    
    void push(int val) {
         _stack.push_back(Val {
            .val = val,
            .min = _stack.empty() || _stack.back().min > val
                ? val : _stack.back().min
        });
    }
    
    void pop() {
        _stack.pop_back();
    }
    
    int top() {
        return _stack.back().val;
    }
    
    int getMin() {
        return _stack.back().min;
    }

private:
    std::list<Val> _stack;
};
