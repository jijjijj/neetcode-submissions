class Solution {
public:
    // +k-1 loops + map
    // +k-2 loops + two pointer
    // two pointer + recursion
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::ranges::sort(nums);
        ksum(0, target, nums, 4);
        return res;
    }

private:
    void ksum(int start, long long target, const std::vector<int>& nums, int k) {
        if (k == 2) {
            int l = start;
            int r = nums.size() - 1;
            while (l < r) {
                const long long cur = 0ll +
                    nums[l] + nums[r];
                if (cur == target) {
                    quad.emplace_back(nums[l]);
                    quad.emplace_back(nums[r]);
                    res.push_back(quad);
                    quad.pop_back();
                    quad.pop_back();
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                } else if (cur > target) {
                    --r;
                } else {
                    ++l;
                }
            }

            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            quad.emplace_back(nums[i]);
            ksum(i + 1, target - nums[i], nums, k - 1);
            quad.pop_back();
        }
    }

    std::vector<std::vector<int>> res;
    std::vector<int> quad;
};