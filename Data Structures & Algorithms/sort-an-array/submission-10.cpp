#include <ranges>

class Solution {
public:
    // +quick sort - +iterative
    // +merge sort - +iterative
    // +heap sort - +iterative
    // radix sort
    // +counting sort
    // shell sort
    // insertion sort
    // selection sort
    // bucket sort
    vector<int> sortArray(vector<int>& nums) {
        const int n = nums.size();
        
        std::vector<int> pos, neg;
    
        for (const int val : nums) {
            if (val < 0) {
                neg.emplace_back(-val);
            } else {
                pos.emplace_back(val);
            }
        }

        radix(pos);
        radix(neg);

        int to = 0;
                
        for (const int val : neg | std::views::reverse) nums[to++] = -val;
        for (const int val : pos) nums[to++] = val;

        return nums;
    }

private:
    void radix(std::vector<int>& nums) {
        if (nums.empty()) return;

        const int n = nums.size();
        
        int max = *std::max_element(
            nums.begin(), nums.end());
        int d = 1;

        std::vector<int> tmp(nums.size());
        while (max / d) {
            std::vector<int> dig(10);

            for (const int val : nums) {
                ++dig[(val / d) % 10];
            }

            for (int i = 1; i < 10; ++i) {
                dig[i] += dig[i - 1];
                // std::cout << dig[i] << " ";
            }
            // std::cout << std::endl;

            for (const int val : nums | std::views::reverse) {
                int& freq = dig[(val / d) % 10];

                tmp[--freq] = val;
            }

            // for (int v : tmp) std::cout << v << " ";
            // std::cout << std::endl;

            d *= 10;
            std::swap(nums, tmp);
        }
    }
};