class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n =s.size();
        
        set<string> dict;
        for(auto w: wordDict)
            dict.insert(w);
        
        vector<bool> dp(n+1,false);
        dp[0] = true; 
        
    
        for(int i=0;i<n;i++)
        {
          
            for(int j=i;j>=0;j--)
            {
                string curr = s.substr(j,i-j+1);
                 cout<<" curr : "<<curr<<endl;
                if(dict.find(curr)!=dict.end())
                    dp[i+1] = dp[i+1] || dp[j]; 
                
                if(dp[i+1])
                    break;
            }
            cout<<endl;
        }
        
        return dp[n];
    }
};