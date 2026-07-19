class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> cars; // pos, speed

        for (int i = 0; i < position.size(); ++i) {
            cars.emplace_back(std::pair{ position[i], speed[i] });
        }

        std::ranges::sort(cars);

        const auto time = [target](const auto& car) {
            return (target - car.first) / static_cast<double>(car.second);
        };

        int fleets = 1;
        float till_end = time(cars.back());

        for (int i = cars.size() - 2; i >= 0; --i) {
            if (time(cars[i]) > till_end) {
                ++fleets;
                till_end = time(cars[i]);
            }
        }

        return fleets;
    }
};
