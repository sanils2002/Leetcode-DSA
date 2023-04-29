class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C;
        
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> mp1, mp2;
            for(int j = 0; j <= i; j++) {
                mp1[A[j]]++;
                mp2[B[j]]++;
            }
            
            int val = 0;
            for(int k = 0; k <= i; k++) {
                if(mp1.find(A[k]) != mp1.end() and mp2.find(B[k]) != mp2.end())
                    val += min(mp1[A[k]], mp2[A[k]]); 
            }
            
            C.push_back(val);
        }
        
        return C;
    }
};