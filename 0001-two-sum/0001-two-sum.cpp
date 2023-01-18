class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> v;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 if(nums[i]+nums[j]==target)
//                 {
//                     v.push_back(i);
//                     v.push_back(j);
//                 }
//             }
//         }
        
//         return v;
        
   unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		if (hash.find(target - nums[i]) != hash.end()) {                  
			result.push_back(hash[target - nums[i]]);
			result.push_back(i);			
			return result;
		}
		hash[nums[i]] = i;
	}
	return result;
    }
};