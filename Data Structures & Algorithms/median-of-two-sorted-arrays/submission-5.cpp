class Solution {
public:
    double findMedianSortedArrays(
        vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) std::swap(nums1, nums2);

        int l = 0;
        int r = nums1.size();

        while (l <= r) {
            const int i = l + (r - l) / 2;
            const int j = (nums1.size() + nums2.size() + 1) / 2 - i;

            const int left_1 = i > 0 ? nums1[i - 1] : INT_MIN;
            const int right_1 = i < nums1.size() ? nums1[i] : INT_MAX;

            const int left_2 = j > 0 ? nums2[j - 1] : INT_MIN;
            const int right_2 = j < nums2.size() ? nums2[j] : INT_MAX;

            if (left_1 <= right_2 && left_2 <= right_1) {
                if ((nums1.size() + nums2.size()) % 2) return std::max(left_1, left_2);

                return (static_cast<double>(std::max(left_1, left_2)) +
                    static_cast<double>(std::min(right_1, right_2))) / 2.0;
            } else if (left_1 > right_2) {
                r = i - 1;
            } else if (left_2 > right_1) {
                l = i + 1;
            }
        }

        return 0.0;
    }
};
