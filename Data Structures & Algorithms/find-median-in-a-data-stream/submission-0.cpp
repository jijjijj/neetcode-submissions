class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (!lower.empty() && num > lower.top()) {
            upper.push(num);
        } else {
            lower.push(num);
        }

        int diff = static_cast<int>(lower.size()) -
            static_cast<int>(upper.size());
        if (diff <= -2) {
            int t = upper.top();
            upper.pop();
            lower.push(t);
        } else if (diff >= 2) {
            int t = lower.top();
            lower.pop();
            upper.push(t);
        }
    }
    
    double findMedian() {
        if (lower.size() == upper.size()) {
            return (static_cast<double>(lower.top()) +
                static_cast<double>(upper.top())) / 2.0;
        }

        return lower.size() > upper.size() ? lower.top() : upper.top();
    }

private:
    std::priority_queue<int> lower; // lower half
    std::priority_queue<int, std::vector<int>,
        std::greater<int>> upper; // upper half
};
