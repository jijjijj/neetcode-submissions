class Solution {
public:
    bool makesquare(vector<int>& nums) {
        std::ranges::sort(nums);
        const int total = std::accumulate(
            nums.begin(), nums.end(), 0);

        if (total % 4) return false;

        return dfs(total / 4, nums, 0, 0, 0);
    }

private:
    bool dfs(int total, std::vector<int>& nums, int i,
        int side, int cur) {
        if (side == 4) {
            return true;
        }

        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j] == nums[i]) continue;
            if (cur + nums[j] > total) continue;

            int next_cur = cur + nums[j];
            std::swap(nums[j], nums[i]);

            int next_side = next_cur == total ? side + 1 : side;
            if (next_cur == total) next_cur = 0;
            if (dfs(total, nums, i + 1, next_side, next_cur)) return true;
            // std::swap(nums[j], nums[i]);
        }

        for (int j = nums.size() - 1; j >= i; --j) std::swap(nums[j], nums[i]);

        return false;
    }
};