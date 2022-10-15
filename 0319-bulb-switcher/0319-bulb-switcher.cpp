class Solution {
public:
    int bulbSwitch(int n) {
        int nb = 0, idx = 1;
        while(idx * idx <= n)
            nb += 1, idx += 1;
        return nb;
    }
};