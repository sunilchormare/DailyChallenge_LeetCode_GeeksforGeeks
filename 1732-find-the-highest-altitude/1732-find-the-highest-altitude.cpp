class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        vector<int> t;
        t.push_back(0);
        for(int i=0;i<gain.size();++i)
        {
            t.push_back(t[i]+gain[i]);
        }
        for(int i=0;i<t.size();++i)
            maxi=max(maxi,t[i]);
            
        return maxi;
    }
};