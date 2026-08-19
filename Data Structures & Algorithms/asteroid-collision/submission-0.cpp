#include <ranges>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> s;

        for (const int val : asteroids) {
            if (s.empty() ||
                std::signbit(val) == std::signbit(s.top())) {
                s.push(val);
            } else {
                const int a = std::abs(val);
                const int borig = s.top();
                const int b = std::abs(borig);
                s.pop();
                if (a != b) s.push(a > b ? a : borig);
            }
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