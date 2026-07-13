class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();

        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = n1;

        while (l <= r) {
            const int mid1 = l + (r - l) / 2;
            const int mid2 = (n1 + n2 + 1) / 2 - mid1;

            int l1 = std::numeric_limits<int>::min();
            int r1 = std::numeric_limits<int>::max();
            int l2 = l1;
            int r2 = r1;
            
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];

            if (mid1 > 0) l1 = nums1[mid1 - 1];
            if (mid2 > 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2) {
                    // odd
                    return std::max(l1, l2);
                }

                return static_cast<double>(std::max(l1, l2) +
                    std::min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }

        return 0.0;
    }
};
