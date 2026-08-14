class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (second.empty()) second.push(num);
        else {
            if (num < second.top()) {
                first.push(num);

                if (first.size() > second.size()) {
                    const int t = first.top();
                    first.pop();
                    second.push(t);
                }
            } else {
                second.push(num);

                if (second.size() > first.size() + 1) {
                    const int t = second.top();
                    second.pop();
                    first.push(t);
                }
            }
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
