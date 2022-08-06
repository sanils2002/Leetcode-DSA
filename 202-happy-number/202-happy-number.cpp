class Solution {
private:
    int process(int n){
        int sum = 0, idx;
        while(0 != n){
            idx = n%10;
            sum += idx * idx;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int sum = 0, count = 0; 
        while(1 != sum){
            sum = process(n);
            n = sum;
            count++;
            if(count > 5) break;
        }
        return 1 == sum? true : false;
    }
};