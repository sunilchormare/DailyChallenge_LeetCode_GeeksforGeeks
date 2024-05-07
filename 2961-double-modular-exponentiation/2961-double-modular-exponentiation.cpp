class Solution {
public:
    long long customPow(int base, int exponent, int mod) {
        long long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        int i = 0;
        for (auto row : variables) {
            long long ele1 = customPow(row[0], row[1], 10);
            long long ele2 = customPow(ele1 % 10, row[2], row[3]);

            if (ele2 == target) {
                ans.push_back(i);
            }

            i++;
        }
        return ans;
    }
};