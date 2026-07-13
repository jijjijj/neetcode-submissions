class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int bits[32] = {};
        int bits_ref[32] = {};

        for (uint32_t i = 1; i < nums.size(); ++i) {
            for (uint8_t j = 0; j < 32; ++j)
                bits_ref[j] += ((i >> j) & 1);
        }

        for (uint32_t i = 0; i < nums.size(); ++i) {
            for (uint8_t j = 0; j < 32; ++j)
                bits[j] += ((nums[i] >> j) & 1);
        }

        int num = 0;

        for (uint8_t i = 0; i < 32; ++i) {
            // std::cout << (int)i << ": " << bits[i] << " " << bits_ref[i] << std::endl;
            num |= ((bits[i] > bits_ref[i]) << i);
        }

        return num;
    }
};
