class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
         int idx=0;
        for(int i=0;i<nums.size()&&idx<groups.size();i++) {
            if(i+groups[idx].size()-1<nums.size()) {
                int j=0;
                for(j=0;j<groups[idx].size();j++) {
                    if(groups[idx][j]!=nums[i+j]) break;
                }
                if(j==groups[idx].size()) {
                    i+=groups[idx].size()-1;
                    idx++;
                }
            }
        }
        return idx>=groups.size();
    }
};