class Solution {
public:
    string pushDominoes(string dominoes) {
        int gameSize = dominoes.size();
        vector<int> forRyt(gameSize, 0), forLft(gameSize ,0);
        int forMag = 0;
        
        //Traverse from Left Wall
        for(int idx = 0 ; idx < gameSize ; idx++) {
            if('R' == dominoes[idx])
                forMag = gameSize;
            else if('L' == dominoes[idx])
                forMag = 0;
            else 
                forMag = max(forMag - 1, 0);
            forRyt[idx] = forMag; //Force towards Right
        }
        
        forMag = 0;
        //Traverse from Right Wall
        for(int idx = gameSize - 1 ; idx >= 0 ; idx--) {
            if('L' == dominoes[idx])
                forMag = gameSize;
            else if('R' == dominoes[idx])
                forMag = 0;
            else 
                forMag = max(forMag-1, 0);
            forLft[idx] = forMag; //Force towards Left
        }
        
        string FinState = "";
        for(int idx = 0 ; idx < gameSize ; idx++) {
            if(forLft[idx] > forRyt[idx])
                FinState += 'L';
            else if(forLft[idx] < forRyt[idx])
                FinState += 'R';
            else 
                FinState += '.';
        }
        
        return FinState;
    }
};