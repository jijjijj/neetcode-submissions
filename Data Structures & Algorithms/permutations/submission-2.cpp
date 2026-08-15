class Solution {
public:
    // iter.
    // swap-based backtracking
    vector<vector<int>> permute(vector<int>& nums) {
        res.push_back({});

        for (int i = 0; i < nums.size(); ++i) {
            decltype(res) new_res;

            for (const auto& perm : res) {
                for (int j = 0; j <= perm.size(); ++j) {
                    std::vector<int> p = perm;
                    p.insert(p.begin() + j, nums[i]);
                    new_res.emplace_back(std::move(p));
                }
            }

            res = std::move(new_res);
        }

        return res;
    }


    std::vector<std::vector<int>> res;
};
