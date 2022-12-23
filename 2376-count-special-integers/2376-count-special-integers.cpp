class Solution {
public:
//     bool isSpecial(int n)
//     {
//         set<char> s;
//         string t=to_string(n);
//         for(char c:t)
//             s.insert(c);
//         return s.size()==t.size()?true:false;
//     }
//     int countSpecialNumbers(int n) {
        
//         if(n<=10) return n;
//         int count=10;
//         for(int i=11;i<=n;++i)
//         {
//             if(isSpecial(i))
//                 count++;
//         }
//         return count;
//     }
    int count(int i, int m) {
    return i == 0 ? 1 : count(i - 1, m) * (m - i + 1);
}
int dfs(int i, int mask, string& s) {
    if (i >= s.size())
        return 1;
    int res = 0, cur = s[i] - '0';
    for (int j = i > 0 ? 0 : 1; j < cur; ++j)
        if ((mask & (1 << j)) == 0)
            res += count(s.size() - i - 1, 9 - i); 
    return res + ((mask & (1 << cur)) == 0 ? dfs(i + 1, mask + (1 << cur), s) : 0); 
}
int countSpecialNumbers(int n) {
    string s = to_string(n);
    int res = dfs(0, 0, s);
    for (int i = 1; i < s.size(); ++i)
        res += 9 * count(i - 1, 9);
    return res;
} 
};