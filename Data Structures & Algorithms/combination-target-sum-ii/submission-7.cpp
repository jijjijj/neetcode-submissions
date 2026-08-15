class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates,
        int target) {
        std::vector<int> nums;
        std::unordered_map<int, int> freq;

        for (int c : candidates) {
            if (!freq[c]++)
                nums.emplace_back(c);
        }

        std::vector<int> cur;

        dfs(target, cur, freq, nums, 0);

        return res;
    }

private:
    void dfs(int left, std::vector<int>& cur,
        std::unordered_map<int, int>& freq,
        const vector<int>& nums, int i) {
        if (!left) {
            res.emplace_back(cur);
            return;
        }
        if (i >= nums.size() || left < 0) return;

        for (; i < nums.size(); ++i) {
            if (!freq[nums[i]]) continue;

            --freq[nums[i]];
            cur.emplace_back(nums[i]);
            dfs(left - nums[i], cur, freq, nums, i);
            cur.pop_back();
            ++freq[nums[i]];
        }
    }

    std::vector<std::vector<int>> res;
};
