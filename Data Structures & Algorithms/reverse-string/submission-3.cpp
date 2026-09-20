class Solution {
public:
    // rec
    // stack
    void reverseString(vector<char>& str) {
        reverse(str, 0, str.size() - 1);
    }

private:
    void reverse(vector<char>& str,
        int l, int r) {
        if (l < r) {
            reverse(str, l + 1, r - 1);
            std::swap(str[l], str[r]);
        }
    }
};