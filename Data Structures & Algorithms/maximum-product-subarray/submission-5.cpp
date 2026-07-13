class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = std::numeric_limits<int>::min();
        int maxN = 1;
        int minN = 1;

        for (int num : nums) {
            const int tmp = maxN * num;
            maxN = std::max({ tmp, minN * num, num });
            minN = std::min({ tmp, minN * num, num });
            max = std::max(max, maxN);
        }

        return max;
    }
};
