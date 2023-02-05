class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while (k-- > 0) {
        long long max_gifts = 0;
        long long max_gifts_index = 0;
        for(int i = 0; i < gifts.size(); i++) {
            if(gifts[i] > max_gifts) {
                max_gifts = gifts[i];
                max_gifts_index = i;
            }
        }
            
            long long num_gifts = gifts[max_gifts_index];
            long long num_gifts_left = floor(sqrt(num_gifts));
            gifts[max_gifts_index] -= num_gifts - num_gifts_left;
        }

        long long total_gifts = 0;
        for(int i = 0; i < gifts.size(); i++) {
            total_gifts += gifts[i];
        }
        
        return total_gifts;
    }
};