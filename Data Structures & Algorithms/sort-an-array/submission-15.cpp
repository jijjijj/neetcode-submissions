#include <ranges>

class Solution {
public:
    // +quick sort - +iterative
    // +merge sort - +iterative
    // +heap sort - +iterative
    // +radix sort
    // +counting sort
    // +shell sort
    // +insertion sort
    // +selection sort
    // bucket sort
    vector<int> sortArray(vector<int>& nums) {
        const int n = nums.size();
        const int max = *std::max_element(nums.begin(), nums.end());
        const int min = *std::min_element(nums.begin(), nums.end());
        const int k = std::max(1, n / 2);
        const int bsize = (max - min) / k + 1;
        
        std::vector<std::vector<int>> buckets(k);

        for (const int val : nums) {
            const int idx = std::min(k - 1,
                (val - min) / bsize);
            buckets[idx].emplace_back(val);
        }

        for (auto& bucket : buckets) {
            for (int i = 1; i < bucket.size(); ++i) {
                int tmp = bucket[i];
                int j = i - 1;
                // 3(0) 2(1)
                for (; j >= 0 && bucket[j] > tmp; --j) {
                    bucket[j + 1] = bucket[j];
                }
                bucket[j + 1] = tmp;
            }
        }

        int to = 0;

        for (const auto& bucket : buckets) {
            for (const int val : bucket) {
                nums[to++] = val;
            }
        }

        return nums;
    }
};