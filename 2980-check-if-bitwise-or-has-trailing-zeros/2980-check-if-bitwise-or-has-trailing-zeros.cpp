class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
            int evenCnt = 0;
        for (int n : nums) {
            if (n % 2 == 0 && ++evenCnt >= 2) return true;
        }
        return false;
    }
};