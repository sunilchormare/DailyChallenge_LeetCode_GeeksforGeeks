class Solution {
public:
   bool checkDistances(string s, vector<int>& dist) {
    for (int i = 0; i < s.size(); ++i) {
        int d = dist[s[i] - 'a'];
        if (i + d + 1 >= s.size() || s[i + d + 1] != s[i])
            return false;
        dist[s[i] - 'a'] = -1;
    }
    return true;
}
};