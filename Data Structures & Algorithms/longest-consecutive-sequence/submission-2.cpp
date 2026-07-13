class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 1) return 1;

        int max = 0;

        std::unordered_set<int> present(nums.begin(), nums.end());

        for (int num : present) {
            if (present.count(num - 1)) continue;

            int i = num;
            while (present.count(++i));

            max = std::max(i - num, max);
        }

        return max;
    }
};
