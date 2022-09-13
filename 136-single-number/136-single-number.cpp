class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Time: O(n) Space:O(n)
        // unordered_map<int,int> c;
        // for(auto i:nums) c[i]++;
        // for(int i=0;i<nums.size();++i)
        //     if(c[nums[i]]==1)
        //         return nums[i];
        // return 0;    
        
        int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;  
    }
};