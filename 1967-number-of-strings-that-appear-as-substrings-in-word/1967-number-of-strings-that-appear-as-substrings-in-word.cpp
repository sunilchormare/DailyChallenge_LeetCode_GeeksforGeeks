class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
       int res = 0;
        for(string &p: patterns){
            if(word.find(p) != std::string::npos){
                res ++;
            }
        }
        return res;
    }
};