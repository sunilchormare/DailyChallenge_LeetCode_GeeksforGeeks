class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int winner = 0;
        for(int opponent = 0; opponent<grid[0].size(); opponent++){
            if(opponent==winner){
                continue;
            }
            if(grid[winner][opponent]==0){
                winner = opponent;
            }
        }
        return winner;
    }
};