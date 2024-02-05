class Solution {
public:
    int minimumPushes(string word) {
        int res = 0;
        for (int i = 0; i < word.size(); i++)
            res += i / 8 + 1;
        return res;
    }
};