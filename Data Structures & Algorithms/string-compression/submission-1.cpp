class Solution {
public:
    int compress(vector<char>& chars) {
        const int n = chars.size();

        int at = 0;
        int i = 0;

        while (i < n) {
            const int j = i;
            while (i < n && chars[i] == chars[j]) {
                ++i;
            }
            
            chars[at++] = chars[j];

            int cnt = (i - j);
            if (cnt > 1) {
                const int k = at;
                while (cnt) {
                    chars[at++] = '0' + (cnt % 10);
                    cnt /= 10;
                }
                std::reverse(chars.begin() + k, chars.begin() + at);
            }
        }

        return at;
    }
};