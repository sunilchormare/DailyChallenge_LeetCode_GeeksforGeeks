class Solution {
public:
  bool canBeValid(string s, string l) {
    if (s.size() % 2 == 1) return false;
    int total = 0, open = 0, closed = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if (l[i] == '0')
            total += 1;
        else if (s[i] == '(')
            open += 1;
        else if (s[i] == ')')
            closed += 1;
        if (total - open + closed < 0) return false;
    }
    total = open = closed = 0;
    for(int i = 0; i < s.size(); i++) {
        if (l[i] == '0')
            total += 1;
        else if (s[i] == '(')
            open += 1;
        else if (s[i] == ')')
            closed += 1;
        if (total + open - closed < 0) return false;
    }
    return true;
}
};