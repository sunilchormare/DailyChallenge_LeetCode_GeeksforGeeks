class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations)
    {   int res = 0;
        for (auto operation: operations)  
            res += operation[1] == '+' ? 1 : -1;
        return res;
    }
};