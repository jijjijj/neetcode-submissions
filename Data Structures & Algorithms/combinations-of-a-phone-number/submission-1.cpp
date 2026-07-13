class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        std::vector<std::string> result;
        std::vector<std::string> nums = { "abc", "def",
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        result.emplace_back("");

        for (char d : digits) {
            std::vector<std::string> new_result;
            for (const auto& comb : result) {
                for (char c : nums[d - '2']) {
                    new_result.emplace_back(comb + c);
                }
            }
            result = std::move(new_result);
        }

        return result;
    }
};
