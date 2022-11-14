class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size())
        return {};
    
    vector<int> res;
    vector<int> freq(26), curr(26);
    
    for(char ch : p)
        freq[ch-'a']++;
    
    int k = p.size();
    //sliding window
    for(int i=0; i<k;i++)
        curr[s[i]-'a']++;
    
    if(curr == freq)
        res.push_back(0);
    
    for(int i=k;i<s.size();i++){
        curr[s[i-k]-'a']--;//removed
        curr[s[i]-'a']++; //added
          if(curr == freq)
            res.push_back(i-k+1);
    }
    
    return res;
    }
};