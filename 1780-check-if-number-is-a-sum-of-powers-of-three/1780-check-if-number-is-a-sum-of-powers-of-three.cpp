class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n!=0)
        {
            int d = n%3;
            {
                if(d == 2)
                    return false;
            }
            n/=3;
        }
        return true;
    }
};