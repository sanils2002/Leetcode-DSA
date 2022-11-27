class Solution {
public:
    int bestClosingTime(string customer) {
       int n = customer.size(), t = (customer[0] == 'Y'), maxi = t, ind = t;

        vector<int> pre(n,0);
        pre[0] = t;

        for(int i = 1; i<n; i++)
        {
            t = (customer[i] == 'Y');
            pre[i] = pre[i-1] + t;
            int temp = 2 * pre[i] - i - 1;

            if(temp > maxi)
            {
                maxi = temp;
                ind = i+1;
            }
        }

        return ind;
    }
};