class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(int a:nums1)
        {
            s.insert(a);
        }
        
        for(int i=0;i<nums2.size();++i)
        {
            if(s.count(nums2[i]))
            {
                return nums2[i];
            }
        }
        
        return -1;
    }
};