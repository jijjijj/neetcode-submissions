class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> s;

        for (const auto& op : operations) {
            if (op == "+") {
                const int a = s.back(); s.pop_back();
                const int b = s.back();

                s.push_back(a);
                s.push_back(a + b);
            } else if (op == "C") {
                s.pop_back();
            } else if (op == "D") {
                s.push_back(s.back() * 2);
            } else {
                s.push_back(std::stoi(op));
            }
        }

        return std::accumulate(s.begin(), s.end(), 0);
    }
};