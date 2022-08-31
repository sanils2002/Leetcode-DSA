class Solution {
public:
    string maximumTime(string time) {
        char h1, h2, m1, m2;
        h1 = time[0], h2 = time[1], m1 = time[3], m2 = time[4];
        
        if('?' == h1 and '?' == h2)
            h1 = '2', h2 = '3';
        else if('?' == h1)
            (h2 - '0' < 4) ? h1 = '2' : h1 = '1';
        else if('?' == h2)
            (2 == h1 - '0') ? h2 = '3' : h2 = '9';
        
        if('?' == m1)
            m1 = '5';
        if('?' == m2)
            m2 = '9';
        
        time[0] = h1, time[1] = h2, time[3] = m1, time[4] = m2;
        
        return time;
    }
};