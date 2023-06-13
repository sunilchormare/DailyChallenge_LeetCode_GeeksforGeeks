class Solution {
public:
    
    int equalPairs(vector<vector<int>>& grid) {
    
        vector<vector<int>> temp;
        for(int j=0;j<grid[0].size();++j)
        {
            vector<int> a;
            for(int i=0;i<grid.size();++i)
            {
                a.push_back(grid[i][j]);
            }
            temp.push_back(a);
        }
        int ans=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<temp.size();++j)
            {
                if(grid[i]==temp[j])
                    ans++;
            }
        }
        return ans;
    }
};