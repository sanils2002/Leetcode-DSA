class LUPrefix {
public:
    vector<bool> prefix;
    int sz = 1;
    LUPrefix(int n) {
        vector<bool> check(n+2, false);
        prefix = check;
        prefix[0] = true;
        int sz = 1;
    }
    
    void upload(int video) {
        prefix[video] = true;
        while(prefix[sz])
            sz++;
    }
    
    int longest() {
        return sz - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */