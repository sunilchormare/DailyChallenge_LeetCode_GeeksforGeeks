class Solution {
public:
    int missingNumber(vector<int>& nums) {
    //      int sum = nums.size();
    // for (int i = 0; i < nums.size(); i++)
    //     sum += i - nums[i];
    // return sum;
//          int xors = 0,i = 0;
// 	for (i = 0; i < nums.size(); i++) {
// 		xors = xors ^ i ^ nums[i];
//         cout<<"i= "<<i<<" nums[i] = "<<nums[i]<<" xors = "<<xors<<endl;
// 	}

// 	return xors ^ i;
          int sum = 0;
        for(int num: nums)
            sum += num;
            
        return (nums.size() * (nums.size() + 1) )/ 2 - sum;
    }
};