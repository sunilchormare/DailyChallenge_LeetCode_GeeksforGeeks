class Solution {
public:
  
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0) return 0;
        int numberOfIslands=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j,m,n);
                    numberOfIslands+=1;
                    
                }
            }
        }
        return numberOfIslands;
    }
      void dfs(vector<vector<char>>& grid,int x,int y,int m,int n)
    {
        if(x<0||x>=m||y<0||y>=n||grid[x][y]!='1')
            return;
        grid[x][y]='2';
        dfs(grid,x-1,y,m,n);
        dfs(grid,x,y-1,m,n);
        dfs(grid,x+1,y,m,n);
        dfs(grid,x,y+1,m,n);
        
    }
};