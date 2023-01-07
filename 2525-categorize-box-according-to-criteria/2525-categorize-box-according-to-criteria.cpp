class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long vol = (long long)length * width * height;
        // string ss_t = to_string(length * width * height);
        
        // cout << ss_t << "\n";
        
        int n = 0;
        // for(auto &c : ss_t) {
        //     if(' ' != c)
        //         n++;
        // }
        if(length >= 10000 or width >= 10000 or height >= 10000 or vol >= 1000000000) {
            if(mass >= 100) {
                return "Both";
            }
            else
                return "Bulky";
        }
        else {
            if(mass >= 100) {
                return "Heavy";
            }
            else
                return "Neither";
        }
    }
};