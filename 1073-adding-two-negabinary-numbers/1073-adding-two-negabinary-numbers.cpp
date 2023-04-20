class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        stack<int> s;
        int i = arr1.size() - 1, j = arr2.size() - 1, carry = 0;
        while(i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if(i >= 0) 
                sum += arr1[i--];
            if(j >= 0) 
                sum += arr2[j--];
            s.push(sum & 1);
            carry = -(sum >> 1);
        }
        
        while(!s.empty() && s.top() == 0) 
            s.pop(); // remove leading zeros
        while(!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        
        if(result.empty()) 
            result.push_back(0); // the result is zero
        return result;
    }
};