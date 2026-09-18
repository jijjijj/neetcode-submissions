class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        const int max = *std::max_element(people.begin(), people.end());
        std::vector<int> freq(max + 1);
        for (const int val : people) ++freq[val];
        int at = 0;
        for (int i = 0; i <= max; ++i) {
            if (!freq[i]--) continue;

            people[at++] = i;
        }

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