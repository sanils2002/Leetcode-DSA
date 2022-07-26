class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string l="";
        for(auto x : s) {
          if(x==' '){
              if(l!=""){v.push_back(l);}
              l=""; continue;}
            else{l+=x;}
        }
        if(l!=""){v.push_back(l);}
        
        reverse(v.begin(), v.end());
        string rev = "";
       for(int i=0;i<v.size();i++){
           if(v[i]==" "){continue;}
           rev+=v[i]; 
           if(i==v.size()-1){break;}
           rev+=" ";
           
       }
        return rev;
    }
};