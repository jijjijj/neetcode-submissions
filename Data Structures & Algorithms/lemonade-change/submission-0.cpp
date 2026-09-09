class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        std::vector<int> b(21);

        for (int i = 0; i < bills.size(); ++i) {
            const int rem = bills[i] - 5;
            if (rem > 0 && !deduct(b, rem))
                return false;
            ++b[bills[i]];
        }

        return true;
    }

private:
    bool deduct(std::vector<int>& b, int rem) {
        if (b[rem]) {
            --b[rem];
            return true;
        }

        if (rem == 15) {
            if (b[5] >= 3) {
                b[5] -= 3;
                return true;
            }

            if (b[10] && b[5]) {
                --b[5];
                --b[10];
                return true;
            }
        }

        return false;
    }
};