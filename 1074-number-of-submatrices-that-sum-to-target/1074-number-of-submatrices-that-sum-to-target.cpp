class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
         int res = 0, m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                A[i][j] += A[i][j - 1];
      
      
        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++) 
            {
              map<int,int> counter;
                counter[0]=1;
                int cur = 0;
                for (int k = 0; k < m; k++) 
                {
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                    res += counter[cur - target];
                    counter[cur]=counter[cur]+ 1;
                }
            }
        }
        return res;
    }
};