class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::ranges::sort(people);

        int l = 0;
        int r = people.size() - 1;
        int ans = 0;

        while (l <= r) {
            ++ans;
            if (people[l] + people[r] > limit) {
                --r;
            } else {
                --r;
                ++l;
            }
        }

        return ans;
    }
};