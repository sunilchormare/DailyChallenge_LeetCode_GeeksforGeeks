class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
    vector<bool> ans;
    int c=*max_element (candies.begin(), candies.end());
    for(auto i:candies)
      ans.push_back((extraCandies+i>=c));
    return ans;    
        
    }
};