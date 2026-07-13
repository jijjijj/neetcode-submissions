class Solution {
public:
    string encode(vector<string>& strs) {
        std::string result;

        for (const auto& str : strs) {
            result += static_cast<char>(str.size() & 0xff);
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        std::vector<string> result;

        for (size_t i = 0; i < s.size(); ) {
            const size_t length = static_cast<size_t>(
                static_cast<unsigned char>(s[i]));

            result.emplace_back(s.substr(i + 1, length));
            i += length + 1;
        }

        return result;
    }
};
