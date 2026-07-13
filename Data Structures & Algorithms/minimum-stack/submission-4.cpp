class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
         _stack.push_back(val - _min);
        //  std::cout << "pushh: " << val << " = " << (val - _min) << ", min = " << std::min(static_cast<long>(val), _min) << std::endl;
         _min = std::min(static_cast<long>(val), _min);
    }
    
    void pop() {
        // std::cout << "pop: " << _min << " " << _stack.back() << std::endl;
        _min -= std::min(0l, _stack.back());
        _stack.pop_back();
    }
    
    int top() {
        return _stack.back() + _min;
    }
    
    int getMin() {
        return _min;
    }

private:
    std::list<long> _stack;
    long _min = std::numeric_limits<long>::max();
};
