class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
            vector<string> res;
    while(s.length()%k!=0){
         s.push_back(fill);   
        }
        for(int i=0;i<=s.length()-k;i+=k){
            res.push_back(s.substr(i,k));
        }
return res;
    }
};