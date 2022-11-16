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
        int st = 1, en = n;
        while(st <= en) {
            int mid = st + (en - st) / 2;
            int val = guess(mid);
            if(0 == val)
                return mid;
            else if(val < 0)
                en = mid - 1;
            else
                st = mid + 1;
        }
        return -1;
    }
};