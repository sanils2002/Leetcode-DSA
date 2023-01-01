class Solution {
public:
    int countDigits(int num) {
        int x = num;
        int cnt = 0;
        
        while(x > 0) {
            int val = x % 10;
            if(0 == num % val)
                cnt++;
            x/= 10;
            //cout << num << endl;
        }
        return cnt;
    }
};