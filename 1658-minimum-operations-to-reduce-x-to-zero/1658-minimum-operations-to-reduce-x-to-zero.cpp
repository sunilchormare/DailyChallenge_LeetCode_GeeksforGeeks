class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      
     int target = -x;
        for (auto num : nums)
            target += num;
        int n = nums.size();
        if (target == 0) return n;
        
       // cout << target  << endl;
        
        unordered_map<int, int> left; // left[Sum(0..i)] = i
        
        left[0] = -1;
        
        int sum = 0, res = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if (left.find(sum - target) != left.end()) 
            {
                 //cout << "i = "<<i << "  " << sum << " " << left[sum-target] << endl;
                res = max(res, i - left[sum-target]);
                //cout<<"res = "<<res<<endl;
            }
            left[sum] = i;
        }
        return (res == INT_MIN ? -1 : n - res);
        
    }
};