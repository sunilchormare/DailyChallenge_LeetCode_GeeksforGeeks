class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0) return ans;
        
        sort(intervals.begin(),intervals.end());
        vector<int> tem=intervals[0];
        for(auto it : intervals)
        {
            if(it[0]<=tem[1])
                tem[1]=max(it[1],tem[1]);
            else
            {
                ans.push_back(tem);
                tem=it;
            }
        }
        ans.push_back(tem);
        return ans;
    }
};