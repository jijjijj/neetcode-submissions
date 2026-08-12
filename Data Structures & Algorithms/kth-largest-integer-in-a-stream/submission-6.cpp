class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k{ k } {
        for (int v : nums) add(v);
    }
    
    int add(int val) {
        if (q.empty() || val > q.top()) {
            q.push(val);

            if (q.size() > k) q.pop();
        }

        return q.top();
    }

private:
    int k{};
    std::priority_queue<int,
        std::vector<int>,
        std::greater<>> q;
};
