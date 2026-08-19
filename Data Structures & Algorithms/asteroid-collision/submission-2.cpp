#include <ranges>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> s;

        for (int val : asteroids) {
            std::optional<int> res = val;
            while (!s.empty() &&
                s.top() > 0 && *res < 0) {
                int abs = std::abs(*res);
                int top = s.top();
                int abstop = std::abs(top);

                s.pop();

                if (abs != abstop) res = abs > abstop ? res : top;
                else {
                    res = {};
                    break;
                }
            }

            if (res) s.push(*res);
        }

        std::vector<int> res;

        while (!s.empty()) {
            res.emplace_back(s.top());
            s.pop();
        }

        std::ranges::reverse(res);

        return res;
    }
};