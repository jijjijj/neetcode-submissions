class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m - 1;
        int i = n - 1;
        int t = nums1.size() - 1;
        
        while (i >= 0) {
            if (j >= 0 && nums1[j] > nums2[i]) {
                nums1[t--] = nums1[j--];
            } else {
                nums1[t--] = nums2[i--];
            }
        }
    }
};