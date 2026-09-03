#include <ranges>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& s) {
        int j = -1;

        for (int v : s) {
            int a = v;

            while (j >= 0 && s[j] > 0 && a < 0) {
                const int diff = a + s[j];

                if (diff > 0) {
                    a = 0;
                } else if (diff < 0) {
                    --j;
                } else {
                    a = 0;
                    --j;
                }
            }

            if (a) s[++j] = a;
        }
        s.resize(j + 1);
        return s;
    }
};