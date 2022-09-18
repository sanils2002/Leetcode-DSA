class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string st = max(arriveAlice, arriveBob), en = min(leaveAlice, leaveBob);
        
        int startmn, startdt, endmn, enddt;
        if(st <= en) {
            startmn = stoi(st.substr(0,2)), startdt = stoi(st.substr(3,2));
            endmn = stoi(en.substr(0,2)), enddt = stoi(en.substr(3,2));
            
            if(endmn == startmn)
                return (enddt - startdt + 1);
            
            int cnt = months[startmn] - startdt;
            for(int idx = startmn + 1 ; idx < endmn ; idx++)
                cnt += months[idx];
            
            cnt += enddt + 1;
            return cnt;
        }
        return 0;
    }
};