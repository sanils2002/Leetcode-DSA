class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
           int n=score.size();
        vector<pair<int,vector<int>>>vt;
        vector<vector<int>>ans;
          for(int i=0;i<score.size();i++){
              vector<int>tem;
                int f;
                 for(int j=0;j<score[0].size();j++){
                         if(j==k){
                                f=score[i][j];
                             
                         }
                     
                       tem.push_back(score[i][j]);
                 }
                vt.push_back({f,tem});
          }
               
        
        sort(vt.begin(),vt.end());
        reverse(vt.begin(),vt.end());
          for(int i=0;i<n;i++){
                vector<int>tem;
                for(int j=0;j<vt[i].second.size();j++){
                      tem.push_back(vt[i].second[j]);
                }
              ans.push_back(tem);
          }
        
          return ans;
           
         
             
        
    }
};