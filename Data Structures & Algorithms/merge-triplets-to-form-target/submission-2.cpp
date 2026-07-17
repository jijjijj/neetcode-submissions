class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a{};
        bool b{};
        bool c{};

        for (const auto& t : triplets) {
            a |= t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2];
            b |= t[0] <= target[0] && t[1] == target[1] && t[2] <= target[2];
            c |= t[0] <= target[0] && t[1] <= target[1] && t[2] == target[2];

            if (a && b && c) return true;
        }

        return false;
    }
};
