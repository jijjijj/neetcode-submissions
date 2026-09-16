class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0;
        int c10 = 0;
        int c20 = 0;

        for (const int c : bills) {
            if (c == 5) ++c5;
            else if (c == 10) {
                ++c10;
                if (!c5--) return false;
            } else {
                if (c10 && c5) {
                    --c10;
                    --c5;
                } else if (c5 >= 3) {
                    c5 -=3;
                } else return false;
            }
        }

        return true;
    }
};