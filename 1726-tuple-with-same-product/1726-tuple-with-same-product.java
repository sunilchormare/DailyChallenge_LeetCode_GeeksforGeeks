class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // int res=0;
        // int n=nums.size();
        // for(int i=0;i<n;++i)
        // {
        //     for(int j=0;j<n;++j)
        //     {
        //         for(int k=0;k<n;++k)
        //         {
        //             for(int l=0;l<n;++l)
        //             {
        //                 if(nums[i]!=nums[j]&&nums[j]!=nums[k]&&nums[k]!=nums[l]&&nums[l]!=nums[i]
        //                   && nums[l]!=nums[j]&&nums[i]*nums[j]==nums[k]*nums[l])
        //                     res++;
        //             }
        //         }
        //     }
        // }
        // return res;
        
        int n = nums.size();
        unordered_map<int,int> umap;
        int res = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < i ; ++j){
                int prod = nums[i] * nums[j];
				/*Every tuple has 8 permutations*/
                res += 8 * umap[prod];
                ++umap[prod];
            }
        }
        return res;
    }
};