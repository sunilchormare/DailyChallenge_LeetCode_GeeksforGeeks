class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int c=0;
//         int n=matrix.size();
//         vector<int> m;
//         for(int i=0;i<matrix.size();++i)
//         {
//             for(int j=0;j<matrix[i].size();++j)
//             {
//                 m.push_back(matrix[i][j]);
//             }
//         }
//          // for(int i=0;i<m.size();++i)
//          //        cout<<m[i]<<" ";

//         return m[k-1];
        
        
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1] + 1, mid, count, tmp;
        
        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2, tmp = n - 1, count = 0;
          
            for (int i = 0; i < n; i++) {
                while (tmp >= 0 && matrix[i][tmp] > mid) tmp--;
                count += tmp + 1;
            }
            
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        
        return lo;  
    }
};