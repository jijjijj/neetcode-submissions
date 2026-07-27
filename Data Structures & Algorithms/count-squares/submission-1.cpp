class CountSquares {
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ++mpx[point[1]][point[0]];
        ++mpy[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        int ways = 0;
        // std::cout << point[0] << " " << point[1] << ": ";
        for (const auto [x, cnt] : mpx[point[1]]) {
            // std::cout << x << " " << cnt << std::endl;
            const int side = std::abs(x - point[0]);

            if (!side) continue;
            
            ways += check_square(point[0], point[1],
                point[0] + side, point[1] + side);
            ways += check_square(point[0], point[1],
                point[0] - side, point[1] + side);
            ways += check_square(point[0], point[1],
                point[0] + side, point[1] - side);
            ways += check_square(point[0], point[1],
                point[0] - side, point[1] - side);
        }
        // std::cout << std::endl;
        return ways;
    }

private:
    int check_square(int x1, int y1, int x2, int y2) {
        return mpy[x2][y2] * mpy[x1][y2] * mpy[x2][y1];
    }

    std::unordered_map<int,
        std::unordered_map<int, int>> mpx;
    std::unordered_map<int,
        std::unordered_map<int, int>> mpy;
};
