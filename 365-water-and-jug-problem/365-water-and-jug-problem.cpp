class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int m = jug1Capacity, n = jug2Capacity;
        if(targetCapacity > m + n)
            return false;
        if(m > n)
            swap(m, n);
        
        int temp;
        while(m) {
            temp = m;
            m = n%m;
            n = temp;
        }
        
        if(0 == targetCapacity % n)
            return true;
        else 
            return false;
    }
};