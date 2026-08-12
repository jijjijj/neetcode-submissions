class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k{ k } {
        for (int v : nums) {
            add(v);
        }
    }
    
    int add(int val) {
        q.push({ val, q.size() });

        if (q.size() > k) q.pop();

        return q.top().first;
    }

private:
    int k{};
    std::priority_queue<std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<>> q;
};
