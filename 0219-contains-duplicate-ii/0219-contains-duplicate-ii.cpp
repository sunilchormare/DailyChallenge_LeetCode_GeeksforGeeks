class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) 
                st.erase(nums[i - k - 1]);    
            if (!st.insert(nums[i]).second) 
                return true;
        }
        return false;
    }
};