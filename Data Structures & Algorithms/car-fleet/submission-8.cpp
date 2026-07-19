#include <ranges>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> cars; // pos, speed

        for (int i = 0; i < position.size(); ++i) {
            cars.emplace_back(std::pair{ position[i], speed[i] });
        }

        std::ranges::sort(cars | std::views::reverse);

        const auto time = [target](const auto& car) {
            return (target - car.first) /
                static_cast<double>(car.second);
        };

        std::vector<double> s;

        for (const auto& c : cars) {
            s.emplace_back(time(c));

            if (s.size() > 1 && s[s.size() - 2] >= s.back()) s.pop_back();
        }

        return s.size();
    }
};
