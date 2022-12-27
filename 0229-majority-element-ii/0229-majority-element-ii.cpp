class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        //if(n<3) return nums;
        unordered_map<int,int> m;
        for(int a:nums)
            m[a]++;
        set<int> res;
        for(int i=0;i<n;++i)
        {
            if(m[nums[i]]>n/3)
                res.insert(nums[i]);
        }
        vector<int> t(res.begin(),res.end());
        return t;
    }
};