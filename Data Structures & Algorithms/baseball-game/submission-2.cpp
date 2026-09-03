class Solution {
public:
    int calPoints(vector<string>& operations) {
        int res = 0;
        std::vector<int> s;

        for (const auto& op : operations) {
            if (op == "+") {
                const int a = s.back(); s.pop_back();
                const int b = s.back();
                res += a + b;
                s.push_back(a);
                s.push_back(a + b);
            } else if (op == "C") {
                res -= s.back();
                s.pop_back();
            } else if (op == "D") {
                res += s.back() * 2;
                s.push_back(s.back() * 2);
            } else {
                s.push_back(std::stoi(op));
                res += s.back();
            }
        }

        return res;
    }
};