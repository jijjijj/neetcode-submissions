class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::ranges::sort(candidates);

        std::vector<int> nums;
        std::unordered_map<int, int> freq;

        for (int c : candidates) {
            if (!freq.contains(c)) nums.emplace_back(c);

            ++freq[c];
        }

        std::vector<std::vector<int>> result;
        std::vector<int> comb;

        dfs(nums, 0, comb, result, target, 0, freq);

        return result;
    }

private:
    void dfs(const std::vector<int>& nums, int i, std::vector<int>& comb,
        std::vector<std::vector<int>>& result, int target, int curr,
        std::unordered_map<int, int>& freq) {
        if (curr == target) {
            result.emplace_back(comb);
            return;
        }

        if (curr > target || i >= nums.size()) return;

        if (freq[nums[i]]) {
            --freq[nums[i]];
            comb.emplace_back(nums[i]);
            dfs(nums, i, comb, result, target, curr + nums[i], freq);
            comb.pop_back();
            ++freq[nums[i]];
        }

        dfs(nums, i + 1, comb, result, target, curr, freq);
    }
};
