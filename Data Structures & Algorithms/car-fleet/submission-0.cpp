class Solution {
private:
    struct Car {
        int pos{};
        int speed{};

        bool operator<(const Car& b) {
            return pos > b.pos;
        }
    };

    int time(int pos_a, int target, int speed) {
        if (!speed) return 2000;

        const int delta = target - pos_a;

        return delta / speed + !!(delta % speed);
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const size_t n = position.size();
        std::vector<Car> cars;
        cars.reserve(n);
        for (size_t i = 0; i < n; ++i) {
            cars.emplace_back(Car{
                .pos = position[i],
                .speed = speed[i]
            });
        }

        std::sort(cars.begin(), cars.end());

        int to_end = time(cars[0].pos, target, cars[0].speed);
        int fleets = 1;

        // std::cout << cars[0].pos << " " << to_end << std::endl;

        for (size_t i = 1; i < n; ++i) {
            // std::cout << "speed delta = " << (cars[i].speed - cars[i - 1].speed) << std::endl;
            // std::cout << "pos delta = " << (cars[i - 1].pos - cars[i].pos) << std::endl;
            const bool will_catch = (cars[i].speed - cars[i - 1].speed) *
                to_end >= (cars[i - 1].pos - cars[i].pos);

            // std::cout << will_catch << std::endl;

            if (!will_catch) {
                to_end = time(cars[i].pos, target, cars[i].speed);
                ++fleets;
            }
        }

        return fleets;
    }
};
