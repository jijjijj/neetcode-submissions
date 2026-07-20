class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int left = (nums1.size() + nums2.size() - 1) / 2;
        const int right = (nums1.size() + nums2.size()) / 2;

        return (get_kth(nums1, 0, nums2, 0, left) +
            get_kth(nums1, 0, nums2, 0, right)) / 2.0; 
    }

private:
    double get_kth(
        const std::vector<int>& a, int froma,
        const std::vector<int>& b, int fromb,
        int k) {
        const int asize = a.size() - froma;
        const int bsize = b.size() - fromb;

        if (asize > bsize) {
            std::swap(a, b);
            std::swap(froma, fromb);
            std::swap(asize, bsize);
        }

        if (!asize) return b[fromb + k - 1];
        if (k == 1) return std::min(a[froma], b[fromb]);

        const int i = std::min(asize, k / 2);
        const int j = std::min(bsize, k / 2);

        if (a[froma] >= b[fromb]) {
            return get_kth(a, froma)
        } else {

        }
    }
};
