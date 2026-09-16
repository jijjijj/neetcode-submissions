class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0;
        int c10 = 0;
        int c20 = 0;

        for (const int c : bills) {
            switch (c) {
                case 5:
                    ++c5;
                    break;
                case 10:
                    ++c10;
                    --c5;
                    break;
                case 20: {
                    if (c10 && c5) {
                        --c10;
                        --c5;
                    } else {
                        c5 -= 3;
                    }
                }
            }

            if (c5 < 0) return false;
        }

        return true;
    }
};