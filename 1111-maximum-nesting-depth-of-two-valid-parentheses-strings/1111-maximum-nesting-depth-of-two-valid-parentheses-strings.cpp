class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.length());
        for (int i = 0; i < seq.length(); ++i)
            res[i] = i & 1 ^ (seq[i] == '(');
        return res; 
    }
};