class Solution {
    float time(int target, int position, int speed) {
        return static_cast<float>(target - position) / static_cast<float>(speed);
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        cars.reserve(position.size());

        for (size_t i = 0; i < position.size(); ++i)
            cars.emplace_back(std::make_pair(position[i], speed[i]));

        std::ranges::sort(cars);

        int fleets = 1;
        float till_end = time(target, cars.back().first, cars.back().second);

        for (int i = cars.size() - 2; i >= 0; --i) {
            float tm = time(target, cars[i].first, cars[i].second);

            if (tm > till_end) {
                ++fleets;
                tm = till_end;
            }
        }

        return fleets;
    }
};
