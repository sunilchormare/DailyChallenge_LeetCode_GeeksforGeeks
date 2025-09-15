class Solution {
public:
   int canBeTypedWords(string text, string brokenLetters) {
    unordered_set<int> broken(begin(brokenLetters), end(brokenLetters));
    int res = 0;
    for (int i = 0, cnt = 0; i <= text.size(); ++i)
        if (i == text.size() || text[i] == ' ') {
            res += cnt == 0;
            cnt = 0;
        }
        else if(cnt == 0)
            cnt += broken.count(text[i]);
    return res;
    }
};