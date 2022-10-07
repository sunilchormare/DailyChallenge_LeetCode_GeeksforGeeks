class Solution {
public:
    vector<vector<int>> m;
    bool subsetSum(vector<int> &nums,int n,int pos,int sum)
    {
        if(sum==0) return true;
        else if(pos>=n||sum<0) return false;
        if(m[pos][sum]!=-1)
            return m[pos][sum];
        return m[pos][sum]=subsetSum(nums,n,pos+1,sum-nums[pos])||subsetSum(nums,n,pos+1,sum);
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;++i)
            sum+=nums[i];
        if(sum&1) return false;
        m.clear();
        m.resize(n+1,vector<int>(sum/2+1,-1));
       return subsetSum(nums,n,0,sum/2);
    }
};