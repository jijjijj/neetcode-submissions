class Solution {
public:
    string predictPartyVictory(string senate) {
        // RRDDD

        int total_r = std::count(senate.begin(), senate.end(), 'R');
        int total_d = std::count(senate.begin(), senate.end(), 'D');

        int r = 0;
        int d = 0;

        while (total_r > 0 && total_d > 0) {
            for (char& c : senate) {
                if (c == 'R') {
                    if (r) {
                        c = 'X';
                        --r;
                    } else {
                        ++d;
                        --total_d;
                    }
                } else if (c == 'D') {
                    if (d) {
                        c = 'X';
                        --d;
                    } else {
                        ++r;
                        --total_r;
                    }
                }
            }
        }

        return total_r > total_d ? "Radiant" : "Dire";
    }
};