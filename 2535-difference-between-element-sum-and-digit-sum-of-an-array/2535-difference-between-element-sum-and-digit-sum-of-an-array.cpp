class Solution {
public:
    int digitSum(int n)
    {
        int sum=0;
        while(n!=0)
        {
            int no=n%10;
            sum+=no;
            n/=10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int eleSum=0;
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            eleSum+=nums[i];
        }
        for(int i=0;i<nums.size();++i)
        {
            sum+=digitSum(nums[i]);
        }
        return abs(eleSum-sum);
    }
};