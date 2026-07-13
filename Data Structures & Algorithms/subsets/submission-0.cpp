class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;

        result.emplace_back(std::vector<int>{}); // seed

        std::unordered_map<int, int> ind;
        for (int i = 0; i < nums.size(); ++i) ind[nums[i]] = i;

        int last = 0;

        while (true) {
            const int n = result.size();
            // std::cout << n << " " << last << std::endl;
            for (int i = last; i < n; ++i) {
                const int start_from = result[i].empty()
                    ? 0 : ind[result[i].back()] + 1;

                for (int j = start_from; j < nums.size(); ++j) {
                    std::vector<int> copy;
                    copy.reserve(result[i].size() + 1);
                    copy.assign(result[i].begin(), result[i].end());
                    copy.emplace_back(nums[j]);

                    // std::cout << "added: ";
                    // for (const int v : copy) std::cout << v << " ";
                    // std::cout << std::endl;

                    result.emplace_back(std::move(copy));
                }
            }

            // std::cout << std::endl;

            if (n == result.size()) break;

            last = n;
        }

        return result;
    }
};
