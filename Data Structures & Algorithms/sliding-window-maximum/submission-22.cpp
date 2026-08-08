class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        const int inf = 20000;

        std::vector<int> res;
        res.resize(n - k + 1);

        std::vector<int> left(n, -inf);
        std::vector<int> right(n + 1, -inf);

        for (int i = 0; i < n; ++i) {
            if ((i % k) && i)
                left[i] = std::max(nums[i], left[i - 1]);
            else
                left[i] = nums[i];

            // std::cout << left[i] << " ";
        }
        // std::cout << std::endl;
        for (int i = n - 1; i >= 0; --i) {
            if (!((i+1) % k))
                right[i] = nums[i];
            else
                right[i] = std::max(nums[i], right[i + 1]);

            // std::cout << right[i] << " ";
        }

        for (int i = k - 1, j = 0; i < n; ++i) {
            res[j++] = std::max(right[i - k + 1], left[i]);
        }

        return res;
    }
};
