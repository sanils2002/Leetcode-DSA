class Solution {
public:
    bool winnerOfGame(string colors) {
        int A = 0, B = 0;
        for(int i = 1 ; i < colors.size() - 1 ; i++){
            if(colors[i] == 'A' and colors[i] == colors[i - 1] and colors[i] == colors[i + 1])
                A++;
            
            if(colors[i] == 'B' and colors[i]==colors[i-1] and colors[i] == colors[i + 1])
                B++;
        }
        
        if(A > B) 
            return true;
        return false;
    }
};