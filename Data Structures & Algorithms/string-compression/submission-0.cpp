class Solution {
public:
    int compress(vector<char>& chars) {
        const int n = chars.size();

        int at = 0;
        char c = chars[0];
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (chars[i] == c) {
                ++cnt;
            }
            if (i == n - 1 || chars[i + 1] != c) {
                chars[at++] = c;

                if (cnt > 1) {
                    const int j = at;
                    while (cnt) {
                        chars[at++] = '0' + (cnt % 10);
                        cnt /= 10;
                    }
                    std::reverse(chars.begin() + j, chars.begin() + at);
                }

                cnt = 0;
                if (i < n - 1) c = chars[i + 1];
            }
        }

        return at;
    }
};