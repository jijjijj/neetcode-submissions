/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;

        while (l <= r) {
            const int mid1 = l + (r - l) / 3;
            const int mid2 = r - (r - l) / 3;
            const int ans1 = guess(mid1);
            const int ans2 = guess(mid2);

            if (!ans1) return mid1;
            if (!ans2) return mid2;

            if (ans1 + ans2 == 0) {
                l = mid1 + 1;
                r = mid2 - 1;
            } else if (ans1 == 1) {
                l = mid2 + 1;
            } else {
                r = mid1 - 1;
            }
        }

        return -1;
    }
};