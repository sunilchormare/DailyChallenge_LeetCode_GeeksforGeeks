class Solution {
public:
     vector<string> ans;
    bool solve(string s,vector<string>& words,string temp)
    {
        if(s.size() == 0)
        {
            ans.push_back(temp);
            return true;
        }
        bool flag = 0;
        for(int i = 1; i <= s.size(); i++)
        {
            string str = s.substr(0,i);
            bool f = 0;
            for(int j = 0; j < words.size(); j++)
            {
                if(str == words[j])
                {
                    f = 1;
                    break;
                }
            }
            if(f and solve(s.substr(i),words,temp + str + ' ')) flag = 1;
        }
        return flag;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        solve(s,wordDict,"");
        for(int i = 0; i < ans.size(); i++)
        {
            ans[i].pop_back();
        }
        return ans;
    }
};