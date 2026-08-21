/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mnt) {
        const int n = mnt.length();

        int l = 0;
        int r = n - 1;

        while (l <= r) {
            const int mid = l + (r - l) / 2;
            const int num = mnt.get(mid);
            const bool val = mid < n
                ? (num > mnt.get(mid + 1)) : true;
            
            if (val) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // l is the peak
        int peak = l;

        const int first = mnt.get(0);
        const int on_peak = mnt.get(peak);
        const int last = mnt.get(n - 1);

        if (target >= first && target < on_peak) {
            l = 0;
            r = peak - 1;

            while (l <= r) {
                const int mid = l + (r - l) / 2;
                const int val = mnt.get(mid);

                if (val == target) return mid;
                else if (val > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        if (target <= on_peak && target >= last) {
            l = peak;
            r = n - 1;

            while (l <= r) {
                const int mid = l + (r - l) / 2;
                const int val = mnt.get(mid);

                if (val == target) return mid;
                else if (val > target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};