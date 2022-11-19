class Solution {
public:
    void findCombinations(int i,vector<int> &A,int target,vector<vector<int>> &res,vector<int> &ds)
    {if(i==A.size()){
        if(target==0)
            res.push_back(ds);
        return;
    }
        if(A[i]<=target){
                ds.push_back(A[i]);
            findCombinations(i,A,target-A[i],res,ds);
            ds.pop_back();
        }
        findCombinations(i+1,A,target,res,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
       ios_base::sync_with_stdio(false);
cin.tie(NULL);
        vector<vector<int>> res;
        vector<int>ds;
        findCombinations(0,A,target,res,ds);
        return res;
    }
};