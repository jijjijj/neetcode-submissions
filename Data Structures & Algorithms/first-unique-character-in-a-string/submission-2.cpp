class Solution {
public:
    int firstUniqChar(string s) {
        int mn = s.size();
        for (char c = 'a'; c <= 'z'; ++c) {
            const int pos = s.find(c);

            if (pos != std::string::npos &&
                s.find(c, pos + 1) == std::string::npos)
                mn = std::min(mn, pos);
        }

        return mn == s.size() ? -1 : mn;
    }
};