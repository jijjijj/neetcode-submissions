class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;

        std::unordered_set<int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.contains(nums[i])) continue;
            mp.emplace(nums[i]);

            nums[k++] = nums[i];
        }

        return k;
    }
};