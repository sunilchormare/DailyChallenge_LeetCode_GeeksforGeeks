class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       vector<string> ans;
int n = s.size();
unordered_map<string,int> m;
for(int i=0;i<=n-10;i++) m[s.substr(i,10)]++;
for(auto i:m) if(i.second>1) ans.push_back(i.first);
return ans;
    }
};