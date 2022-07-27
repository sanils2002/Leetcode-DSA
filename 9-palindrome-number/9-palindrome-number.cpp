class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int l = 0, r = num.length() - 1;
        while(l < r) {
            if(num[l] != num[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};