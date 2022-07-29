class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     // int n=nums.size()-1;
     //    int sumArr=0;
     //    for(int i:nums)
     //        sumArr+=i;     
     //    int sum=(n*(n+1))/2;
     //    cout<<sum;
     //    return sumArr-sum;
   int idx = 0;
        while (nums[idx] == idx) ++idx;
        while (nums[idx] != idx) {
            int tmp = idx;
            idx = nums[tmp];
            nums[tmp] = tmp;
        }
        return idx;
    }
};