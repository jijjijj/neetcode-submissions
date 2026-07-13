class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        std::stack<int> indices;
        
        for (size_t i = 0; i < t.size(); ++i) {
            while (!indices.empty() && t[i] > t[indices.top()]) {
                const int top = indices.top();
                t[top] = i - top;
                indices.pop();
            }

            indices.push(i);
        }

        while (!indices.empty()) {
            t[indices.top()] = 0;
            indices.pop();
        }

        return t;
    }
};
