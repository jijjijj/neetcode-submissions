class Solution {
public:
    int candy(vector<int>& nums) {
        const int n = nums.size();
        
        int sum = 0;
        int i = 0;

        while (i < n) {
            if ((!i || nums[i] >= nums[i - 1]) &&
                (i == n - 1 || nums[i] >= nums[i + 1])) {
                int l = i;
                int r = i;

                while (l > 0 && nums[l - 1] <= nums[l]) --l;
                while (r + 1 < n && nums[r + 1] <= nums[r]) ++r;

                // std::cout << i << " ";

                const int ni = r + 1;
                if (l) --sum;
                l = i - l + 1;
                r = r - i + 1;
                if (l > r) std::swap(l, r);
                --l;
                // std::cout << l << " " << r << std::endl;
                i = ni;

                sum += (l * (l + 1)) / 2;
                sum += (r * (r + 1)) / 2;

                continue;
            }

            ++i;
        }

        return sum;
    }
};