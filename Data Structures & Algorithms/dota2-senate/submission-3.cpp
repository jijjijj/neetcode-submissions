class Solution {
public:
    string predictPartyVictory(string senate) {
        std::queue<char> r;
        std::queue<char> d;

        for (int i = 0; i < senate.size(); ++i) {
            (senate[i] == 'R' ? r : d).push(i);
        }

        while (!r.empty() && !d.empty()) {
            if (r.front() < d.front()) {
                d.pop();
            } else {
                r.pop();
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};