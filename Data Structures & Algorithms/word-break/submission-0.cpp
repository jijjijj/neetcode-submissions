class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<std::string> words(
            wordDict.begin(), wordDict.end());

        return dfs(s, 0, words);
    }

private:
    bool dfs(const std::string& s, int i,
        const std::unordered_set<std::string>& words) {
        if (i == s.size()) return true;
        
        for (const auto& word : words) {
            if (s.size() - i >= word.size() &&
                s.substr(i, word.size()) == word) {
                if (dfs(s, i + word.size(), words)) {
                    return true;
                }
            }
        }

        return false;
    }
};
