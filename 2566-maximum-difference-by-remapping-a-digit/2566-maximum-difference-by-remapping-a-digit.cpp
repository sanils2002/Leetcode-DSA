class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int max_val = num, min_val = num;

        for(char c = '0'; c <= '9'; c++) {
            for(char d = '0'; d <= '9'; d++) {
                string temp = s;
                for(int i = 0; i < temp.size(); i++) {
                    if(temp[i] == c) {
                        temp[i] = d;
                    }
                }
                int new_num = stoi(temp);
                if(new_num > max_val) {
                    max_val = new_num;
                }
                if(new_num < min_val) {
                    min_val = new_num;
                }
            }
        }

        int diff = max_val - min_val;
        return diff;
    }
};