class Solution 
{
public:
    int maximumSum(vector<int>& v) 
    {
        int res = 0, n = v.size();
        int cur_max = v[0], overall_max = v[0];
        vector<int> f(n);
        vector<int> b(n);
        f[0] = v[0];
        
        for(int i = 1; i < n; i++)
        {
            cur_max = max(v[i], cur_max + v[i]); 
            overall_max = max(overall_max, cur_max); 
  
            f[i] = cur_max; 
        }
        
        cur_max = overall_max = b[n - 1] = v[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            cur_max = max(v[i], cur_max + v[i]); 
            overall_max = max(overall_max, cur_max); 

            b[i] = cur_max; 
        }
        
        res = overall_max;
        for(int i = 1; i < n - 1; i++)
        {
            res = max(res, f[i - 1] + b[i + 1]);
        }
        return res;
    }
};