class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        const int n = stones.size();

        std::vector<int> postfix(n + 1);
        for (int i = n - 1; i >= 0; --i)
            postfix[i] = postfix[i + 1] + stones[i];

        std::vector<int> dp(n + 1, -5 * 10000 * 1000 - 1);
        dp.back() = 0;

        for (int i = n - 1; i >= 0; --i) {
            int sum = 0;
            for (int j = 1; j <= std::min(3, n - i); ++j) {
                sum += stones[i + j - 1];
                dp[i] = std::max(dp[i], sum + postfix[i + j] - dp[i + j]);
            }
        }

        const int alice = dp[0];
        const int bob = postfix[0] - alice;
        // std::cout << alice << " " << bob << std::endl;
        return bob > alice ? "Bob" : (bob == alice ? "Tie" : "Alice");
    }
};