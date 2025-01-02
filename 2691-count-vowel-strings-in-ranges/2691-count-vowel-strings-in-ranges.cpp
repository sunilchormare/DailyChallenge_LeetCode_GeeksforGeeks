class Solution {
public:
   vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
         int n = w.size();
        vector<int> sum(n);
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        for (int i = 0; i < n; i++) {
            if (vowels.count(w[i][0]) && vowels.count(w[i][w[i].size() - 1])) {
                sum[i] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            sum[i] += sum[i - 1];
        }
        vector<int> ans;
        for (auto qr : q) {
            int li = qr[0], ri = qr[1];
            if (li == 0) {
                ans.push_back(sum[ri]);
            } else {
                ans.push_back(sum[ri] - sum[li - 1]);
            }
        }
        return ans;
    }
};