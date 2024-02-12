// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> m;
//         for(int i=0;i<nums.size();i++)
//             m[nums[i]]++;
//         int res=0,maxi=0;
//         for(int i=0;i<nums.size();i++)
//         {   if(m[nums[i]]>maxi)
//                {
//                    maxi=m[nums[i]];
//                    res=nums[i];
//                 }
               
//                }
// return res;
//                }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};