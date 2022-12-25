class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        // Check if the target exists in the array
        bool targetExists = false;
        for(string word : words) {
            if(word == target) {
                targetExists = true;
                break;
            }
        }
  
        if(!targetExists) {
            return -1;
        }

        int n = words.size();
        int minDistance = INT_MAX;

        // Check the distance in both directions
        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                // Calculate the distance in the forward direction
                int distance = i - startIndex;
                if(distance < 0) {
                    distance += n;
                }
                minDistance = min(minDistance, distance);

                // Calculate the distance in the backward direction
                distance = startIndex - i;
                if(distance < 0) {
                    distance += n;
                }
                minDistance = min(minDistance, distance);
            }
        }

        return minDistance;
    }
};