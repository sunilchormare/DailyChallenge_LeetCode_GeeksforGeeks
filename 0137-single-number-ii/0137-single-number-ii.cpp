class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int> m;
        // for(int i=0;i<nums.size();++i)
        // {
        //     m[nums[i]]++;
        // }
        // for(int i=0;i<nums.size();++i)
        // {
        //     if(m[nums[i]]==1)
        //         return nums[i];
        // }
        // return 0;
        
        int res = 0;
	for (int i = 0; i < 32; i++) {
		int sum = 0;
		int mask = 1 << i;
		for (auto n : nums) 
			if (n & mask) 
				sum++;
		if (sum % 3 == 1)
			res |= mask;
	}
	return res;
    }
};