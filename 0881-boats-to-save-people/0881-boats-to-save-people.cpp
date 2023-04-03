class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int greedy = 0;
        int i = 0, j = people.size() - 1;
        while(i <= j) {
            greedy++;
            if(people[i] + people[j] <= limit)
                i++;
            j--;
        }
        
        return greedy;
    }
};