class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
         int n = S.size(), pos = -n;
        vector<int> res(n, n);
        for (int i = 0; i < n; ++i) 
        {
            if (S[i] == C) pos = i;
            res[i] = i - pos;
               cout<<" i = "<<i<<" res[i] "<<res[i]<<endl;
        }
         cout<<endl;
        for (int i = pos - 1; i >=0; --i)
        {
            
            if (S[i] == C)  pos = i;
            res[i] = min(res[i], pos - i);
            cout<<" i = "<<i<<" res[i] "<<res[i]<<endl;
        }
        return res; 
    }
};