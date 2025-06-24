class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
       vector<int> res;
    for (int i = 0, j = 0; i < nums.size(); ++i)
        if (nums[i] == key)
            for (j = max(j, i - k); j <= i + k && j < nums.size(); ++j)
                res.push_back(j);
    return res;    
    }
};