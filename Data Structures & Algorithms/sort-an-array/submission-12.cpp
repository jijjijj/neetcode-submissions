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
        
        for (int i = 0; i < n - 1; ++i) {
            int min = i;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            std::swap(nums[min], nums[i]);
        }
        
        return nums;
    }
};