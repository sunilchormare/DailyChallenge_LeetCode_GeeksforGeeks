class Solution {
public:
    int countElements(vector<int>& nums) {
     //  sort(nums.begin(),nums.end());
     //  int count=0;
     //  for(int i=1;i<nums.size()-1;++i)
     //  {
     //      if(nums[i-1]<nums[i]&&nums[i+1]>nums[i])
     //          count++;
     //  }
     // return count;
        
        unordered_map<int,int>map;
        int m=INT_MIN;
        int l=INT_MAX;
        for(int x:nums){
            map[x]++;
            m=max(m,x);
            l=min(l,x);
        }
        if(m==l){
            return 0;
        }
        return nums.size()-map[m]-map[l];
    }
};