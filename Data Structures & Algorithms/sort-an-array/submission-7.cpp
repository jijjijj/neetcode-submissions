class Solution {
public:
    // +quick sort - +iterative
    // +merge sort - +iterative?
    // +heap sort - iterative?
    // radix sort
    // counting sort
    // shell sort
    // insertion sort
    // selection sort
    // bucket sort
    vector<int> sortArray(vector<int>& nums) {
        const int n = nums.size();
        
        for (int i = n / 2 - 1; i >= 0; --i)
            heapify(nums, i, n - 1);

        for (int i = n - 1; i > 0; --i) {
            std::swap(nums[0], nums[i]);
            heapify(nums, 0, i - 1);
        }

        return nums;
    }

private:
    void heapify(std::vector<int>& nums,
        int i, int r) {
        int left = 0;

        while ((left = (i << 1) | 1) <= r) {
            int largest = left;

            const int right = left + 1;

            if (right <= r && nums[right] > nums[left])
                largest = right;
            if (nums[i] >= nums[largest]) return;

            std::swap(nums[i], nums[largest]);
            i = largest;
        }
    }
};