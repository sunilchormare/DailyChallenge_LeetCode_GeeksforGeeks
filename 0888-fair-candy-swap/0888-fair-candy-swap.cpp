class Solution {
public:
vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int diff = (accumulate(A.begin(), A.end(), 0) - 
                    accumulate(B.begin(), B.end(), 0))/2;
        for (auto i : A ) 
            if(find(B.begin(), B.end(), i - diff) != B.end())
                return {i,  i - diff};
        return {};
    }
};