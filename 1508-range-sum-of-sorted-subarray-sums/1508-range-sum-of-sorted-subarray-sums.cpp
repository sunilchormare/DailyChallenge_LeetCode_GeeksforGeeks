class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
//BRUTE FORCE
        //        vector<int> res;
//         // int n=nums.size();
//         for(int i=0;i<n;++i)
//         {
//             int sum=nums[i];
//             res.push_back(sum);
//             for(int j=i+1;j<n;++j)
//             {
//               sum+=nums[j];
//               res.push_back(sum);
//             }
            
//         }
//         int ans=0;
//         sort(res.begin(),res.end());
//         for(int i=left-1;i<right;++i)
//           ans+=res[i];
            
        
//         // for(int i=0;i<res.size();++i)
//         //         cout<<res[i]<<" ";
        
//       return ans%1000000007;  
        vector<int> sums { };
	for (int i = 0; i < n; i++) {
		int prefixSum = 0;
		for (int j = i; j < n; j++) {
			prefixSum += nums[j];
			sums.push_back(prefixSum);
		}
	}
	sort(begin(sums), end(sums));
	int res = accumulate(sums.begin() + left - 1, sums.begin() + right, 0LL) % 1000000007;
	return res;
    }
};