class Solution {
private:
    typedef long long ll;
    ll mod = 1e9+7;
public:
    int countHousePlacements(int n) {
        ll house = 1, plot = 1;
        ll total = house + plot;
        for(int idx = 2 ; idx <= n ; idx++) {
            house = plot;
            plot = total;
            total = (house + plot) % mod;
        }
        
        return (total * total) % mod;
    }
};