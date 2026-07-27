class CountSquares {
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ++mpy[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        int ways = 0;
        // std::cout << point[0] << " " << point[1] << ": ";
        for (const auto [y, _] : mpy[point[0]]) {
            std::cout << "y " << y << std::endl;
            const int side = std::abs(y - point[1]);

            if (!side) continue;
            
            ways += check_square(point[0], point[1],
                point[0] + side, point[1] + side);
            std::cout << ways << std::endl;
            ways += check_square(point[0], point[1],
                point[0] - side, point[1] + side);
            std::cout << ways << std::endl;

            ways += check_square(point[0], point[1],
                point[0] + side, point[1] - side);
            std::cout << ways << std::endl;

            ways += check_square(point[0], point[1],
                point[0] - side, point[1] - side);
            std::cout << ways << std::endl;

        }
        std::cout << std::endl;
        return ways;
    }

private:
    int check_square(int x1, int y1, int x2, int y2) {
        if (!mpy[x2].contains(y2) ||
            !mpy[x1].contains(y2) ||
            !mpy[x2].contains(y1)) return 0;
        return mpy[x2][y2] * mpy[x1][y2] * mpy[x2][y1];
    }

    std::unordered_map<int,
        std::unordered_map<int, int>> mpy;
};
