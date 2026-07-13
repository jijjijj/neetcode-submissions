class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::unordered_map<int, int> memo;
        return std::min(dfs(cost, 0, memo),
            dfs(cost, 1, memo));
    }

private:
    int dfs(const std::vector<int>& cost, int i,
        std::unordered_map<int, int>& memo) {
        if (i >= cost.size()) return 0;
        if (memo.contains(i)) return memo[i];

        return memo[i] =
            std::min(dfs(cost, i + 1, memo) + cost[i],
                dfs(cost, i + 2, memo) + cost[i]);
    }
};
