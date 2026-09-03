#include <ranges>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> res;
        
        for (int v : asteroids) {
            int a = v;

            while (!res.empty() && res.back() > 0 && a < 0) {
                const int diff = a + res.back();

                if (diff > 0) {
                    a = 0;
                } else if (diff < 0) {
                    res.pop_back();
                } else {
                    a = 0;
                    res.pop_back();
                }
            }

            if (a) res.push_back(a);
        }

        return res;
    }
};