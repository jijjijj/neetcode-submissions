class Solution {
public:
    // +bfs
    // +dp with cnt
    // dp with max

    bool canReach(string s, int minJump, int maxJump) {
        const int n = s.size();
        std::vector<bool> dp(n);
        dp[0] = '1' - s[0];

        int max = 0;
        for (int i = 0; i < n; ++i) {
            if (!dp[i]) continue;

            for (int j = std::max(i + minJump, max);
                j <= std::min(i + maxJump, n - 1); ++j) {
                if (s[j] == '0') dp[j] = 1;
            }
            max = i + maxJump + 1;
        }

        return dp.back();
    }
};