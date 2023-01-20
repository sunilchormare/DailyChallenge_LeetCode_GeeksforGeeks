class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
     vector<int>ans;
        priority_queue<int>p;
        for(auto &x:nums)p.push(x);
        while(!p.empty())
        {
            ans.push_back(p.top());
            p.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};