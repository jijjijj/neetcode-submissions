class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        return dfs(piles, 0, 1, 1);
    }

private:
    int dfs(const std::vector<int>& piles, int off, int alice, int m) {
        const int n = piles.size();

        int max = alice ? 0 : 9999;
        int sum = 0;
        for (int x = 1; x <= std::min(2 * m, n - off); ++x) {
            sum += piles[off + x - 1];

            if (alice)
            max = std::max(max, sum + dfs(piles, off + x, !alice, std::max(x, m)));
            else
            max = std::min(max, dfs(piles, off + x, !alice, std::max(x, m)));
        }
        return max;
    }
};