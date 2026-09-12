class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int reach = 0; // index 8
        int reach_s = 0; // index 6

        // 00110010, 2 4
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1' || i < reach_s) continue;
            if (i > reach) break;
            if (i == s.size() - 1) return true;

            reach_s = i + minJump;
            reach = i + maxJump;
        }

        return false;
    }
};