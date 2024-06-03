class Solution {
public:
    int appendCharacters(string s, string t) {
//         int N = B.length();
 
//     int i = 0;
 
//     map<char, set<int> > mp;
//    for (i = 0; i < N; i++) {
//         mp[B[i]].insert(i);
//     }
//     int previous = -1;

//     int ans = 0;
//     for (i = 0; i < A.length(); i++) {
//         char ch = A[i];
//         if (mp[ch].size() == 0) {
//             //cout << -1;
//             //return 0;
//         }
 

//         auto it = mp[ch].upper_bound(previous);
//         if (it == mp[ch].end()) {
 
//             previous = -1;
//             ans++;
//             --i;
//             continue;
//         }
//         previous = *it;
//     }
//    return ans;
//     //cout << ans;
        
        int temp=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[temp])
                temp++;
            if(temp==t.size())
                return 0;
        }
        return t.size()-temp;
    }
};