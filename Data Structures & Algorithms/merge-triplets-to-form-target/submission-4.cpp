class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        std::vector<bool> found(target.size());

        for (const auto& t : triplets) {
            if (t[0] > target[0] ||
                t[1] > target[1] ||
                t[2] > target[2]) continue;
            
            for (int i = 0; i < t.size(); ++i) {
                found[i] = found[i] || (t[i] == target[i]);
            }
        }

        return found[0] && found[1] && found[2];
    }
};
