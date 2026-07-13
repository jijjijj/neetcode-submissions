class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result;

        for (const auto& str : strs) {
            result += static_cast<unsigned char>(str.size());
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;

        for (int i = 0; i < s.size(); ++i) {
            size_t length = static_cast<unsigned char>(s[i]);
            // std::cout << length << " ";
            result.emplace_back(s.substr(i + 1, length));
            i += length;
        }

        return result;
    }
};
