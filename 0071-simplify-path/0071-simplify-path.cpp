class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        stringstream ss(path);
        string dir;
    
        while(getline(ss, dir, '/')) {
            if(dir == "" || dir == ".") {
                continue;
            } 
            else if(dir == "..") {
                if(!dirs.empty()) {
                    dirs.pop_back();
                }
            } 
            else {
                dirs.push_back(dir);
            }
        }
    
        string simplifiedPath = "";
        for(string dir : dirs) {
            simplifiedPath += "/" + dir;
        }
    
        if(simplifiedPath == "") {
            return "/";
        } 
        else {
            return simplifiedPath;
        }
    }
};