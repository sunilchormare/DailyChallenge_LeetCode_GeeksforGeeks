class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
     
        //BRUTE FORCE SOLUTION
        int count=0;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=0;j<nums.size();++j)
            {
                if(i==j) continue;
                if(i<j&&abs(nums[i]-nums[j])==k){
                    count++;
                }
            }
        }
         return count;
    }
};