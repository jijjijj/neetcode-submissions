#include <ranges>

class Solution {
public:
    // +quick sort - +iterative
    // +merge sort - +iterative
    // +heap sort - +iterative
    // +radix sort
    // +counting sort
    // shell sort
    // +insertion sort
    // +selection sort
    // bucket sort
    vector<int> sortArray(vector<int>& nums) {
        const int n = nums.size();
        
        for (int i = n / 2; i > 0; i >>= 1) {
            for (int x = i; x < n; ++x) {
                int tmp = nums[x];

                int j = x - i;
                for (; j >= 0 && nums[j] > tmp; j -= i) {
                    nums[j + i] = nums[j];
                }

                nums[j + i] = tmp;
            }
        }
        
        return nums;
    }
};