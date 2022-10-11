class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        // for(int i=0;i<nums.size();++i)
        //     for(int j=i;j<nums.size();++j)
        //         for(int k=j;k<nums.size();++k)
        //             if(i<j<k&&nums[i]<nums[j]&&nums[j]<nums[k])
        //                 return true;
        // return false;
        
         int small =INT_MAX, big = INT_MAX;
        for (int n : nums) {
            if (n <= small) 
              small = n; 
            else if (n <= big)
               big = n;  
            else 
                  return true;
        }
        return false;
    }
};