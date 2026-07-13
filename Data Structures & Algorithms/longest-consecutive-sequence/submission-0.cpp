class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 1) return 1;

        int max = 0;
        int current = 0;

        std::unordered_set<int> present;
        int min_num = std::numeric_limits<int>::max();
        int max_num = std::numeric_limits<int>::min();

        for (int num : nums) {
            present.emplace(num);
            min_num = std::min(min_num, num);
            max_num = std::max(max_num, num);
        }

        for (int i = min_num; i <= max_num; ++i) {
            if (present.count(i)) ++current;
            else current = 0;

            max = std::max(max, current);
        }

        return max;
    }
};
