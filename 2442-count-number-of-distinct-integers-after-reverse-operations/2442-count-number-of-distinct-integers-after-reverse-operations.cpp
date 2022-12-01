class Solution {
public:
     int reverse(int n)
     {
         int reversed_number = 0, remainder;
  while(n != 0) {
    remainder = n % 10;
    reversed_number = reversed_number * 10 + remainder;
    n /= 10;
  }
         return reversed_number;
     }
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        //nums.resize(nums.size());
        for(int i=0;i<n;++i)
        {
            nums.push_back(reverse(nums[i]));
        }
        set<int> s;
        for(int i:nums)
        {
            s.insert(i);
        }
        return s.size();
    }
};