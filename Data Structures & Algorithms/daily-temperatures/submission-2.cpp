class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        const int n = t.size();
        std::vector<int> result(t.size(), 0);

        for (int i = n - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < n && t[i] >= t[j]) {
                if (!result[j]) {
                    j = n;
                    break;
                }
                j += result[j];
            }

            if (j < n) result[i] = j - i;
        }

        return result;
    }
};
