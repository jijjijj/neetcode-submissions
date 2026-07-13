class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (_stack.empty()) {
            _stack.push_back(0);
            _min = val;
        } else {
            _stack.push_back(val - _min);
            _min = std::min(static_cast<long>(val), _min);
        }
        //  std::cout << "pushh: " << val << " = " << (val - _min) << ", min = " << std::min(static_cast<long>(val), _min) << std::endl;
    }
    
    void pop() {
        _min -= std::min(0l, _stack.back());
        _stack.pop_back();
        // std::cout << "pop: " << _min << std::endl;
    }
    
    int top() {
        return _stack.back() > 0 ? _stack.back() + _min : _min;
    }
    
    int getMin() {
        return _min;
    }

private:
    std::list<long> _stack;
    long _min{};
};
