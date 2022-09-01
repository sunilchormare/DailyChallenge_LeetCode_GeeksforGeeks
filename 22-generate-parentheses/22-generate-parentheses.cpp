class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("",n,n,res);
        return res;
    }
    void helper(string current,int left,int right,vector<string> &res)
    {
        if(left<0||left>right) return;
        if(left==0&&right==0)
        {
            res.push_back(current);
            return;
        }
        helper(current+"(",left-1,right,res);
        helper(current+")",left,right-1,res);
    }
};