class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int h = matrix.size();
        const int w = matrix[0].size();

        std::vector<int> res;
        res.reserve(w * h);

        std::pair<int, int> direction = { 1, 0 };

        int x = 0;
        int y = 0;

        int l = 0;
        int r = w - 1;
        int t = 0;
        int b = h - 1;

        while (res.size() != (w * h)) {
            res.emplace_back(matrix[y][x]);

            const int nx = x + direction.first;
            const int ny = y + direction.second;
            // std::cout << "at " << x << " " << y << " - " << nx << " " << ny << " ";
            if (nx > r) {
                // std::cout << "turn down " << std::endl;
                direction = { 0, 1 };
                x = r;
                y++;
                ++t;
            } else if (nx < l) {
                // std::cout << "turn up " << std::endl;

                direction = { 0, -1 };
                x = l;
                y--;
                --b;
            } else if (ny > b) {
                // std::cout << "turn right " << std::endl;

                direction = { -1, 0 };
                y = b;
                x--;
                --r;
            } else if (ny < t) {
                // std::cout << "turn left " << std::endl;

                direction = { 1, 0 };
                y = t;
                x++;
                ++l;
            } else {
                x = nx;
                y = ny;
            }
        }

        return res;
    }
};
