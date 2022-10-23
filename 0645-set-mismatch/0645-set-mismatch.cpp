class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2,0);
        int sumA=0;
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;++i){
            m[nums[i]]++;
            sumA+=nums[i];
        }
        int sum=(n*(n+1))/2;
        //cout<<sum;
        for(int i=0;i<n;++i)
        {
            if(m[nums[i]]>1)
                res[0]=nums[i],res[1]=sum-(sumA-nums[i]);
        }
         
     return res;
    }
};