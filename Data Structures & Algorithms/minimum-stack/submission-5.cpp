class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
         _stack.push_back(val - _min);
        //  std::cout << "pushh: " << val << " = " << (val - _min) << ", min = " << std::min(static_cast<long>(val), _min) << std::endl;
        _min = _stack.size() == 1 ? val : std::min(static_cast<long>(val), _min);
    }
    
    void pop() {
        _min -= std::min(0l, _stack.back());
        _stack.pop_back();
        _min = _stack.empty() ? 0 : _min;
        // std::cout << "pop: " << _min << std::endl;
    }
    
    int top() {
        return _stack.size() > 1 ? _stack.back() + _min : _min;
    }
    
    int getMin() {
        return _min;
    }

private:
    std::list<long> _stack;
    long _min{};
};
