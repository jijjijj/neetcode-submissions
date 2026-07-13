class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result;

        for (const auto& str : strs) {
            result += static_cast<char>(str.size());
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;

        for (int i = 0; i < s.size(); ++i) {
            size_t length = s[i];
            result.emplace_back(s.substr(i + 1, length));
            i += length;
        }

        return result;
    }
};
