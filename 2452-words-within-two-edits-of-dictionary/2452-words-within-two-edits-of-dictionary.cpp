class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int cnt=0;
        vector<string> v;

        for(int idx = 0 ; idx < queries.size() ; idx++){
            for(int jdx = 0 ; jdx < dictionary.size() ; jdx++){
                cnt=0;
                for(int kdx = 0 ; kdx < dictionary[jdx].size() ; kdx++){
                    if(queries[idx][kdx] != dictionary[jdx][kdx])
                        cnt++;
                }
                if(cnt <= 2) {
                    v.push_back(queries[idx]);
                    break;
                }
            }

        }
        return v;
    }
};