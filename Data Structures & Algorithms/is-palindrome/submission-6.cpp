class Solution {
public:
    bool isPalindrome(string s) {
        std::string copy;

        for (char c : s) {
            if (std::isalnum(c)) copy += std::tolower(c);
        }
        
        return std::string(copy.rbegin(), copy.rend()) == copy;
    }
};
