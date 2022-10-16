class Solution {
public:
    int countTime(string time) {
        int res = 1;
        if('?' == time[0]) {
            if('?' == time[1])
                res *= 24;
            else if('3' >= time[1])
                res *= 3;
            else
                res *= 2;
        }
        else if('?' == time[1])
            res *= time[0] < '2' ? 10 : 4;
        if('?' == time[3])
            res *= 6;
        if('?' == time[4])
            res *= 10;
        return res;
    }
};