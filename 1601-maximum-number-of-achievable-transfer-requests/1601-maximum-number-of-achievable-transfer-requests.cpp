class Solution {
public:
    //int ans=0;
    void helper(int i,int l,vector<int>&temp,vector<vector<int>>&v,int& ans)
    {
       if(i==v.size())
       {
           for(auto a:temp) if(a!=0) return;
           ans=max(ans,l);
           return;
       }
        helper(i+1,l,temp,v,ans);
        temp[v[i][0]]--;
        temp[v[i][1]]++;
        
        helper(i+1,l+1,temp,v,ans);
        temp[v[i][0]]++;
        temp[v[i][1]]--;
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests)
    {
        int ans=0;
        vector<int> temp(n,0);
         helper(0,0,temp,requests,ans);
        return ans;
    }
};