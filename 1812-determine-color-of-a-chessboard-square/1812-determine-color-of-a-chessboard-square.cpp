class Solution {
public:
    bool squareIsWhite(string a) {
        return a[0] % 2 != a[1] % 2;  
    }
};