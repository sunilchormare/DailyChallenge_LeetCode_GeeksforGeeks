class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.size(), ans = 0, begin = 0, end = 0;
        map<char, int> mp;
        while (end < n)
        {
            mp[s[end]]++;
            while (mp[s[end]] == 3)
                mp[s[begin++]]--;
            ans = max(ans, end - begin + 1);
            end++;
        }
        return ans;
    }
};