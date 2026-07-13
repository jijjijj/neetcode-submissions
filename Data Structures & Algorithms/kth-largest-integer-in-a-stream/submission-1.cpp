class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : k{k}, s{ nums.begin(), nums.end() } {
        
        while (s.size() > k) s.pop();
    }
    
    int add(int val) {
        s.push(val);

        if (s.size() > k) s.pop();

        return s.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> s;
    int k{};
};
