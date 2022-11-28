class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> win(100005,0);
        vector<int> loss(100005,0);
        
        for(auto it:matches){
            win[it[0]]++;
            loss[it[1]]++;
        }
        
        vector<vector<int>> ans(2);
        
       for(int i=0;i<loss.size();i++){
           if((loss[i]==0 && win[i]!=0)||(win[i]!=0 && loss[i]==0)){
               ans[0].push_back(i);
           }
           if(loss[i]==1){
               ans[1].push_back(i);
           }
       }

       
        return ans;                                                                                                                                                                                                                                                                                                                                                                              
    }
};