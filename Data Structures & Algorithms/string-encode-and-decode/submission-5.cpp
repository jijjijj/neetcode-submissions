class Solution {
public:
    string encode(vector<string>& strs) {
        std::string result;

        // size_t length = 0;
        // for (const auto& str : strs) length += str.size() + 1;

        // result.reserve(length);

        for (const auto& str : strs) {
            // std::cout << "len = " << (str.size() & 0xff) << std::endl;
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
            // std::cout << "len_ = " << (length) << std::endl;
            result.emplace_back(s.substr(i + 1, length));
            i += length + 1;
        }

        return result;
    }
};
