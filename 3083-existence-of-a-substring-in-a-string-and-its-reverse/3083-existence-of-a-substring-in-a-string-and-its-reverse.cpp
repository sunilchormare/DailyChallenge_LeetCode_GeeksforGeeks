class Solution {
public:
  bool isSubstringPresent(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
    
      string substring = s.substr(i, 2);

    
      reverse(substring.begin(), substring.end());

      
      if (s.find(substring) != string::npos) {
        return true;
      }
    }


    return false;
  }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();