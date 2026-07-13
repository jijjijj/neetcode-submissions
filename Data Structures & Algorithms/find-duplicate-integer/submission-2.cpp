class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int num = 0;

        for (int i = 0; i < 32; ++i) {
            const int mask = 1 << i;

            int bits = 0;

            for (int n : nums) bits += (mask & n);

            int bits_ref = 0;

            for (int i = 1; i < nums.size(); ++i)
                bits_ref += (mask & i);

            num |= (bits > bits_ref) << i;
        }

        return num;
    }
};
