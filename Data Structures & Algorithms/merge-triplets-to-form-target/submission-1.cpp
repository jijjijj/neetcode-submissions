class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = 0;
        int b = 0;
        int c = 0;

        for (const auto& t : triplets) {
            if (t[0] == target[0] &&
                t[1] <= target[1] &&
                t[2] <= target[2]) {
                a = t[0];
                b = t[1];
                c = t[2];
                break;
            }
        }

        for (const auto& t : triplets) {
            if (t[0] <= a &&
                t[1] == target[1] &&
                t[2] <= target[2]) {
                b = target[1];
                c = std::max(c, t[2]);
                break;
            }
        }

        for (const auto& t : triplets) {
            if (t[0] <= a &&
                t[1] <= b &&
                t[2] == target[2]) {
                c = target[2];
                break;
            }
        }

        return std::vector{ a, b, c} == target;
    }
};
