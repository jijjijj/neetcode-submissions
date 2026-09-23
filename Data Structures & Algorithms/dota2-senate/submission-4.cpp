class Solution {
public:
    string predictPartyVictory(string senate) {
        std::queue<int> r;
        std::queue<int> d;

        for (int i = 0; i < senate.size(); ++i) {
            (senate[i] == 'R' ? r : d).push(i);
        }

        while (!r.empty() && !d.empty()) {
            const int a = r.front(); r.pop();
            const int b = d.front(); d.pop();

            if (a < b) {
                r.push(a + senate.size());
            } else {
                d.push(b + senate.size());
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};