class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto num : nums) {
            if(map.find(num) == map.end())
                map[num] = 1;
            else
                map[num] += 1;
        }
        int result = 0;
        for (auto iter = map.begin(); iter != map.end(); ++iter)
            if (map.find(iter->first + 1) != map.end())
                result = max(result, iter->second + map[iter->first + 1]);
        return result;
    }
};