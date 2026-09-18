class Solution {
public:
    // +bfs
    // +dp with cnt
    // dp with max

    bool canReach(string s, int minJump, int maxJump) {
        const int n = s.size();
        
        std::vector<int> sweep(n + 1);
        int curr = 0;

        for (int i = 0; i < n; ++i) {
            curr += sweep[i];

            if (s[i] == '1') continue;
            if (i && !curr) continue;
            if (i == n - 1) return true;

            ++sweep[std::min(i + minJump, n)];
            --sweep[std::min(i + maxJump + 1, n)];
        }

        return false;
    }
};