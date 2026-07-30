class CountSquares {
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ++mpy[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        int ways = 0;
        for (const auto [y, _] : mpy[point[0]]) {
            const int side = y - point[1];

            if (!side) continue;
            
            ways += check_square(point[0], point[1],
                point[0] - side, point[1] + side);
            ways += check_square(point[0], point[1],
                point[0] + side, point[1] + side);
        }
        
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
