class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for(int idx = 0; idx < s.size() ; idx++){
            if(s[idx] == 'I' && s[idx+1] == 'V'){ sum += 4; idx++; } 
            else if(s[idx] == 'I' && s[idx+1] == 'X'){ sum += 9; idx++; } 
            else if(s[idx] == 'X' && s[idx+1] == 'L'){ sum += 40; idx++; } 
            else if(s[idx] == 'X' && s[idx+1] == 'C'){ sum += 90; idx++; } 
            else if(s[idx] == 'C' && s[idx+1] == 'D'){ sum += 400; idx++; } 
            else if(s[idx] == 'C' && s[idx+1] == 'M'){ sum += 900; idx++; } 
            else if(s[idx] == 'I') sum += 1;
            else if(s[idx] == 'V') sum += 5;
            else if(s[idx] == 'X') sum += 10;
            else if(s[idx] == 'L') sum += 50;
            else if(s[idx] == 'C') sum += 100;
            else if(s[idx] == 'D') sum += 500;
            else if(s[idx] == 'M') sum += 1000;
        }
        return sum;
    }
};