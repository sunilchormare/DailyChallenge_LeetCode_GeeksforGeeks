class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
//         for(int i=0;i<A.size();++i)
//         {
//             int p=0,q=A.size()-1;
//             while(p<q)
//                 A[i][p]=A[i][q];
            
//         }
        
//          return A;
    
        
       for (auto& row : A) {
            reverse(row.begin(), row.end());
            for (auto& v : row)
                v ^= 1;
        }
        return A;
        
    }
};