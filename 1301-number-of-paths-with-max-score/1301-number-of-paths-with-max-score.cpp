class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int rows=board.size(), cols=board[0].size();
        vector<vector<int>> paths(rows,vector<int>(cols,0));
        vector<vector<int>>  sums(rows,vector<int>(cols,0));
        vector<vector<int>> dirs = {{-1,0},{0,-1},{-1,-1}};
        paths[rows-1][cols-1] = 1;
        board[0][0] = '0';

        for(int r=rows-1;r>=0;r--) {
            for(int c=cols-1;c>=0;c--) {
                if(paths[r][c]==0) continue; // unreachable
                for(auto d:dirs) {
                    int rr=r+d[0], cc=c+d[1];
                    if(rr<0||cc<0||rr>=rows||cc>=cols) continue; // out of board
                    if(board[rr][cc]=='X') continue;
                    int newsum = (board[rr][cc]-'0' + sums[r][c]) ;
                    if(newsum < sums[rr][cc]) continue;
                    if(newsum > sums[rr][cc]) {
                        paths[rr][cc] = 0, sums[rr][cc]=0; // found a better path
                    }
                    paths[rr][cc] = (paths[r][c] + paths[rr][cc]) % 1000000007;
                    sums[rr][cc] = newsum;
                }
            }
        }
        return {sums[0][0], paths[0][0]};
    }
};