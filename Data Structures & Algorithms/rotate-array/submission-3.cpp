class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        
        int moved = 0;
        for (int start = 0; moved < n; ++start) {
            int prev = nums[start];
            int nxt = start;

            do {
                nxt = (nxt + k) % n;
                const int tmp = nums[nxt];
                nums[nxt] = prev;
                prev = tmp;
                ++moved;
            } while (nxt != start);

            // nums[nxt] = prev;
        }
    }
};