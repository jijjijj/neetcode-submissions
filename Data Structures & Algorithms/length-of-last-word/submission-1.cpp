class Solution {
public:
    int lengthOfLastWord(string s) {
        const auto i = s.find_last_not_of(' ');
        const auto i2 = s.find_last_of(' ', i);

        return i - i2;
    }
};