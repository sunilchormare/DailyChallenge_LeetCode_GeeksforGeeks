class Solution {
public:
    void findCombinations(int in,vector<int> A,int target,vector<vector<int>> &res,vector<int> &ds)
    {
        if(target==0){
            res.push_back(ds);
            return;
        }
        for(int i=in;i<A.size();++i)
        {
            if(i>in&&A[i]==A[i-1]) continue;
            if(A[i]>target) break;
            ds.push_back(A[i]);
            findCombinations(i+1,A,target-A[i],res,ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(A.begin(),A.end());
        findCombinations(0,A,target,res,ds);
        return res;
    }
};