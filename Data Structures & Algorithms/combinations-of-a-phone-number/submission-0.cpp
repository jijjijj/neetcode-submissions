class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> result;
        std::vector<std::string> nums = { "abc", "def",
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        std::string curr;
        dfs(result, nums, digits, 0, curr);

        return result;
    }

private:
    void dfs(std::vector<std::string>& result,
        const std::vector<std::string>& nums,
        const std::string& digits, int i,
        std::string& curr) {
        if (i >= digits.size()) {
            if (i) result.emplace_back(curr);
            return;
        }

        for (char c : nums[digits[i] - '2']) {
            curr.push_back(c);
            dfs(result, nums, digits, i + 1, curr);
            curr.pop_back();
        }
    }
};
