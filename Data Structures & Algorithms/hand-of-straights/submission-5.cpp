class Solution {
public:
    // sorting, priority-queue, ordered map, hash-map
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::unordered_map<int, int> freq;
        for (int n : hand) ++freq[n];

        std::priority_queue<int,
            std::vector<int>, std::greater<>> q;

        for (auto [n, f] : freq) q.push(n);

        while (!q.empty()) {
            int v = q.top();
            
            // if (freq[v]) {
                for (int i = v; i < v + groupSize; ++i) {
                    if (!freq[i]) return false;

                    --freq[i];
                    // std::cout << i << " " << freq[i] << " " << q.top() << std::endl;
                    if (!freq[i] && (i == q.top())) {
                        q.pop();
                    }
                }
            // }
        }

        return true;
    }
};
