class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::stack<std::pair<int, int>> s;
        s.push({ 0, nums.size() - 1 });

        while (!s.empty()) {
            const auto [l, r] = s.top();
            s.pop();

            if (r - l < 2) {
                if (nums[l] > nums[r])
                    std::swap(nums[l], nums[r]);
                continue;
            }

            const int j = partition(nums, l, r);

            s.push({ l, j });
            s.push({ j + 1, r });
        }

        return nums;
    }

private:
    int partition(vector<int>& nums, int l, int r) {
        const int mid = l + (r - l) / 2;
        std::swap(nums[l + 1], nums[mid]);
        
        if (nums[l] > nums[l + 1])
            std::swap(nums[l], nums[l + 1]);
        if (nums[l + 1] > nums[r])
            std::swap(nums[l + 1], nums[r]);
        if (nums[l] > nums[l + 1])
            std::swap(nums[l], nums[l + 1]);

        const int target = nums[l + 1];

        int i = l + 1;
        int j = r;

        while (i <= j) {
            while (nums[++i] < target);
            while (nums[--j] > target);

            if (i > j) break;

            std::swap(nums[j], nums[i]);
        }

        std::swap(nums[l + 1], nums[j]);

        return j;
    }
};