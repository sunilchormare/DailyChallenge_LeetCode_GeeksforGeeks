class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
    int res = 0;
        unordered_map<int, int> count;
        for (int a: nums) 
            res += count[a]++;
        return res;
    }
};