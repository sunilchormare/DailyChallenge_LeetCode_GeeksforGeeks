class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        // vector<int> res;
        // for(int i=0;i<queries.size();++i)
        // {
        //     int tem=nums[queries[i][1]];
        //     nums[queries[i][1]]+=queries[i][0];
        //     int sum=0;
        //     for(int j=0;j<nums.size();++j)
        //     {
        //         if(nums[j]%2==0)
        //             sum+=nums[j];
        //     }
        //     res[i]=sum;
        //     nums[queries[i][1]]=tem;
        // }
        // return res;
         int sum = 0;
        for (int a : A) { 
            sum += (a % 2 == 0 ? a : 0); 
        }
       vector<int> ans(queries.size());
        for (int i = 0; i < ans.size(); ++i) {
            int idx = queries[i][1];
            if (A[idx] % 2 == 0) { 
                sum -= A[idx]; 
            }
            A[idx] += queries[i][0];
            if (A[idx] % 2 == 0) { 
                sum += A[idx]; 
            }
            ans[i] = sum;
        }
        return ans;    
    }
};