class Solution {
public:
    Solution() : sides(4) {}

    bool makesquare(vector<int>& nums) {
        sides.clear();
        sides.resize(4);

        std::ranges::sort(nums);
        const int total = std::accumulate(
            nums.begin(), nums.end(), 0);

        if (total % 4) return false;

        return dfs(total / 4, nums, 0, 0);
    }

private:
    bool dfs(int total, std::vector<int>& nums, int i, uint64_t mask) {
        if (sides[0] == sides[1] && sides[2] == sides[3] &&
            sides[0] == sides[2] && sides[0] == total) {
            return true;
        }

        if (dp.contains(mask)) return false;

        for (int j = 0; j < 4; ++j) {
            if (sides[j] + nums[i] > total) continue;

            sides[j] += nums[i];
            const uint64_t m = mask | (1 << ((j * 16) + i));
            if (dfs(total, nums, i + 1, m)) return true;
            sides[j] -= nums[i];
        }

        dp.emplace(mask);

        return false;
    }

    std::vector<int> sides;
    std::unordered_set<uint64_t> dp;
};