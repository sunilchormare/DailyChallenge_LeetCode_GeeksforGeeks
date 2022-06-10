class Solution {
public:
    vector<int> diStringMatch(string S) {
       vector<int> res(S.size() + 1);
        int l = 0, r = S.size();
        for (int i = 0; i < S.size(); i++) {
            res[i] = S[i] == 'I' ? l++ : r--;
        }
        res[S.size()] = l;
        return res; 
        
        
    }
};