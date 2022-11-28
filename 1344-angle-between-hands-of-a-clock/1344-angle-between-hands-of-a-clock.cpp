class Solution {
public:
    double angleClock(int hour, int minutes) {
        double deg_m = 6 * minutes;
        if(12 == hour)
            hour = 0;
        
        double deg_h = double(hour + minutes/60.0) * 30.0;
        double angle1 = abs(deg_m - deg_h);
        
        return min(angle1, 360.0 - angle1);
    }
};