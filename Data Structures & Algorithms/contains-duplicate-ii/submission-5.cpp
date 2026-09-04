class Solution {
public:
    // +understand why hashset works
    // hashset
    // +hashmap
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::vector<std::pair<int, int>> arr;
        arr.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            arr.emplace_back(std::pair{ nums[i], i });
        }
        std::ranges::sort(arr);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i && arr[i].first == arr[i - 1].first &&
                arr[i].second - arr[i - 1].second <= k) {
                    return true;
            }
        }

        return false;
    }
};