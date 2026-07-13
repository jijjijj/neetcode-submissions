class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        std::stack<int> indices;
        std::vector<int> result(t.size(), 0);

        for (size_t i = 0; i < t.size(); ++i) {
            while (!indices.empty() && t[i] > t[indices.top()]) {
                const int top = indices.top();
                result[top] = i - top;
                indices.pop();
            }

            indices.push(i);
        }

        return result;
    }
};
