class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        int power = 1;
        int len = 0;

        do {
            if (power == len) {
                slow = fast;
                power <<= 1;
                len = 0;
            }

            ++len;
            fast = next(fast);
        } while (slow != fast);

        return slow == 1;
    }

private:
    int next(int n) {
        int power = 0;

        while (n) {
            power += (n % 10) * (n % 10);
            n /= 10;
        }

        return power;
    }
};
