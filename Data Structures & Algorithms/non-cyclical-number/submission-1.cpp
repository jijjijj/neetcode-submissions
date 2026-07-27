class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> s;

        while (n != 1 && !s.contains(n)) {
            int num = n;

            s.emplace(n);

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
