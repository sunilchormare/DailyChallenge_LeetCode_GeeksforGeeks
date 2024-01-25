class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        //Make array of length equal to string length
        vector<int> ans(s.size());
        
        //Now use two for loops 
        for(int i=0;i<s.size();i++){
            //countmoves will keep on counting the valid moves from i to s.length 
            int countMoves=0;
            int yIndex=startPos[0];
            int xIndex=startPos[1];
            for(int j=i;j<s.size();j++){
                
                if(s[j]=='R'){
                    xIndex++;
                }
                if(s[j]=='L'){
                       xIndex--; 
                }
               if(s[j]=='U'){
                        yIndex--;
                }
                if(s[j]=='D'){
                    yIndex++;
                }
                if(xIndex<0 || xIndex>=n || yIndex<0 || yIndex>=n){
                    break;
                }
                else{
                    countMoves++;
                }
            }
            
            ans[i]=countMoves;
            
            
        }
        return ans;
        
    }
};