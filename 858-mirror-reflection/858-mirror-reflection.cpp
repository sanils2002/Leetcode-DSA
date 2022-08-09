class Solution {
private:
    int solve(int tL, int tR, int bR, int bL, int p, int rayDist, int q) {
        if(rayDist == p)
            return tR;
        if(0 == rayDist)
            return bR;
        if(rayDist*2 <= q)
            return solve(tR, tL, bL, bR, p, rayDist + q, q);
        else 
            return solve(bR, bL, tL, tR, p, rayDist + q - p, q);
    }
public:
    int mirrorReflection(int p, int q) {
        int tL = 2, tR = 1, bR = 0, bL = -1;
        return solve(tL, tR, bR, bL, p, q, q);
    }
};