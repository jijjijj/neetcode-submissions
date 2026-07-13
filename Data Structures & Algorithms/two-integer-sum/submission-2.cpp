class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            const int el = nums[i];
            if (const auto it = map.find(target - el); it != map.end()) {
                return std::vector<int>{ it->second, i };
            }
            
            map.insert({ el, i });
        }

        throw std::invalid_argument{""};
    }
};
