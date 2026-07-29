class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast && slow != 1);

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
