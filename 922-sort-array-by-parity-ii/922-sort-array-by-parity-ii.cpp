class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {      
        vector<int> res(A.size());
        int j = 0, k = 1;
        for(int i = 0; i < A.size(); i++) 
        {
            if(A[i] % 2 == 0) 
            {
                res[j] = A[i];
                j += 2;
            }
            else
            {
                res[k] = A[i];
                k += 2;
            }
    }
        return res;
}
};