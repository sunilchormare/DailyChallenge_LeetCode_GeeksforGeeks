class Solution {
public:
    int minSwaps(string s) {
        int swap1 = canAlter('1', s);
        int swap2 = canAlter('0', s);
        int res = min(swap1, swap2);
        return (res == s.size()) ? -1 : res;
    }
    
 int canAlter(char cc, string s) {
        int missOne = 0, missZero = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c != cc) {
                if (c == '1') missOne++;
                else missZero++;
            }
            cc = (cc == '0') ? '1' : '0';
        }
        return missOne == missZero ? missOne : s.size();
    }
};