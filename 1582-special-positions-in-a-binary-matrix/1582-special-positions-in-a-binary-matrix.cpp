class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
//         int count=0;
//         int n=mat.size(),m=mat[0].size();
        
//         for(int i=0;i<n;++i)
//         {
//             for(int j=0;j<m;++j)
//             {
//                 if(mat[i][j]==1&&check(mat,i,j))
//                 {
//                     count++;
//                 }
                
//             }
            
//         }
        
        
//         return count;
//     }
    
//     bool check(vector<vector<int>>& mat,int a,int b)
//     {
//         int c=0;
//         for(int i=0;i<mat.size();++i)
//         {
//             if(mat[a][i]==0) c++;
//         }
//         int d=0;
//         for(int i=0;i<mat[0].size();++i)
//         {
//             if(mat[i][b]==0) d++;
//         }
        
//         if(c==mat.size()-1&&d==mat.size()-1)
//         {
//             return true;
//         }
        
        
//         return false;
//     }
        
        
           vector<int> rows(mat.size()), cols(mat[0].size());
    for (int i = 0; i < rows.size(); ++i)
        for (int j = 0; j < cols.size(); ++j) {
            if (mat[i][j])
                ++rows[i], ++cols[j];
        }
    int res = 0;
    for (int i = 0; i < rows.size(); ++i)
        for (int j = 0; j < cols.size(); ++j)
            if (mat[i][j] && rows[i] == 1 && cols[j] == 1)
                ++res;
    return res;
    }
};