class Solution {
public:
    // +bfs
    // dp with cnt
    // dp with max

    bool canReach(string s, int minJump, int maxJump) {
        const int n = s.size();
        std::vector<bool> dp(n);
        dp[0] = '1' - s[0];

        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (i >= minJump && dp[i - minJump]) ++cnt;
            if (i > maxJump && dp[i - maxJump - 1]) --cnt;

            dp[i] = (cnt > 0) && s[i] == '0';
        }

        return dp.back();
    }
};