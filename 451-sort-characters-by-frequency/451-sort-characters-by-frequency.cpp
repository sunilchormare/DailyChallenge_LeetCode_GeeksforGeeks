class Solution {
public:
    string frequencySort(string s) {
       string res="";
       vector<pair<int,char>> hash('z'+1,{0,0});
       for(char c:s)
           hash[c]={hash[c].first+1,c};
        sort(hash.begin(),hash.end());
        for(auto i:hash)
        {
            res=string(i.first,i.second)+res;
        }
        return res;
    }
};