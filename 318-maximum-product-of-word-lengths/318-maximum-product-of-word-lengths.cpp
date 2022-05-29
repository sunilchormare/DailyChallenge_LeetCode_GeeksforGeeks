class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> value(words.size(), 0);
        for(int i = 0; i < words.size(); ++i)
            for(auto c: words[i])
                value[i] |= 1 << (c - 'a');

        int ret = 0;
        for(int i = 1; i < words.size(); ++i)
            for(int j = 0; j < i; ++j)
                if((value[i] & value[j]) == 0 && words[i].length() * words[j].length() > ret)
                    ret = words[i].length() * words[j].length();
        return ret; 
    }
};