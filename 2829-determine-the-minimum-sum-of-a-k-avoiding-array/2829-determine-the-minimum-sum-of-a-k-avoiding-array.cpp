class Solution {
public:
    int minimumSum(int n, int k) {
        int a = 0;
        set<int> s;
        for(int i = 1 ; n > 0 ; i++){
            if(!s.count(i)){
                n--;
                a += i;
                s.insert(k - i);
            }
        }
        
        return a;
    }
};