class Solution {
public:
    // +quick sort - +iterative
    // +merge sort - +iterative
    // +heap sort - +iterative
    // radix sort
    // counting sort
    // shell sort
    // insertion sort
    // selection sort
    // bucket sort
    vector<int> sortArray(vector<int>& nums) {
        const int n = nums.size();
        
        const int min = *std::min_element(nums.begin(), nums.end());
        const int max = *std::max_element(nums.begin(), nums.end());

        std::vector<int> freq(max - min + 1);

        for (const int val : nums) {
            ++freq[val - min];
        }

        int to = 0;

        for (int cur = 0; cur <= (max - min); ++cur) {
            while (freq[cur]) {
                nums[to++] = min + cur;
                --freq[cur];
            }
        }

        return nums;
    }
};