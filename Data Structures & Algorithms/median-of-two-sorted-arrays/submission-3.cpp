class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int len1 = nums1.size();
        const int len2 = nums2.size();

        int median1 = 0;
        int median2 = 0;

        int i = 0;
        int j = 0;

        for (int k = 0; k < (len1 + len2) / 2 + 1; ++k) {
            median2 = median1;
            if (i < len1 && j < len2) {
                if (nums1[i] < nums2[j]) {
                    median1 = nums1[i];
                    ++i;
                } else {
                    median1 = nums2[j];
                    ++j;
                }
            } else if (i < len1) {
                median1 = nums1[i++];
            } else if (j < len2) {
                median1 = nums2[j++];
            }
        }

        if ((len1 + len2) & 1) return median1;

        return (static_cast<double>(median1) +
            static_cast<double>(median2)) / 2; 
    }
};
