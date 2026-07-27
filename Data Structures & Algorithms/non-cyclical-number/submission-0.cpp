class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> s;
        s.emplace(n);

        while (n != 1 && s.contains(n)) {
            int num = n;

            int power = 0;
            while (num) {
                power += (num % 10) * (num % 10);
                num /= 10;
            }

            n = power;
        }

        return n == 1;
    }
};
