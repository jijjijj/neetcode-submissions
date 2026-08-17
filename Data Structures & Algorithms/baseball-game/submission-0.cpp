class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> s;

        for (const auto& op : operations) {
            if (op == "+") {
                const int a = s.top(); s.pop();
                const int b = s.top();

                s.push(a);
                s.push(a + b);
            } else if (op == "C") {
                s.pop();
            } else if (op == "D") {
                s.push(s.top() * 2);
            } else {
                s.push(std::stoi(op));
            }
        }

        int res = 0;
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};