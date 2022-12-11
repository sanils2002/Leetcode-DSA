class Allocator {
public:
    vector<int> mem;
    Allocator(int n) {
        mem = vector<int> (n, -1);
    }
    
    int allocate(int size, int mID) {
        int cons = 0;
        int i;
        for(i = 0 ; i < mem.size() ; i++) {
            if(-1 == mem[i])
                cons++;
            if(size == cons)
                break;
            if(size != cons and -1 != mem[i])
                cons = 0;
        }
        
        if(cons == size) {
            for(int j = i - cons + 1 ; j <= i ; j++)
                mem[j] = mID;
            return i - cons + 1;
        }
        else
            return -1;
    }
    
    int free(int mID) {
        int count = 0;
        for(int i = 0 ; i < mem.size(); i++){
            if(mem[i]==mID)
                count++, mem[i] = -1;
        }
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */