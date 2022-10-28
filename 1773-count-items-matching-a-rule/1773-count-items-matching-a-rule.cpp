class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
          int i = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
        int ans = 0;
        
        for(auto item : items)
        {
            if(item[i] == ruleValue)
                ans++;
        }
        
       return ans;
    }
};