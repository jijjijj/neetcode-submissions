#include <ranges>

class Solution {
public:
    // +quick sort - +iterative
    // +merge sort - +iterative
    // +heap sort - +iterative
    // +radix sort
    // +counting sort
    // shell sort
    // insertion sort
    // +selection sort
    // bucket sort
    vector<int> sortArray(vector<int>& nums) {
        const int n = nums.size();
        
        for (int i = 1; i < n; ++i) {
            int tmp = nums[i];

            int j = i - 1;
            for (; j >= 0 && nums[j] > tmp; --j) {
                nums[j + 1] = nums[j];
            }

            nums[j + 1] = tmp;
        }
        
        return nums;
    }
};