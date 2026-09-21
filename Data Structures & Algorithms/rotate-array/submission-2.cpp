class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        
        int moved = 0;
        for (int start = 0; moved < n; ++start) {
            int prev = nums[start];
            int nxt = start;

            do {
                const int tmp = nums[nxt];
                nums[nxt] = prev;
                nxt = (nxt + k) % n;
                prev = tmp;
                ++moved;
            } while (nxt != start);

            nums[nxt] = prev;
        }
    }
};