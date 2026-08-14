class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        first.push(num);

        second.push(first.top());
        first.pop();

        if (second.size() > first.size() + 1) {
            const int t = second.top();
            second.pop();
            first.push(t);
        }
    }
    
    double findMedian() {
        if ((first.size() + second.size()) & 1)
            return second.top();

        return (first.top() + second.top()) / 2.0;
    }

private:
    std::priority_queue<double> first;
    std::priority_queue<double, std::vector<double>,
        std::greater<>> second;
};
