class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(int idx = 0 ; idx < matrix.size() ; idx++) {
            for(int jdx = 0 ; jdx < matrix[0].size() ; jdx++) {
                pq.push(matrix[idx][jdx]);
                if(pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};