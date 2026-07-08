#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        int n = queries.size();
        long long MOD = 1000000007;

        vector<int> prefixDigitSum(m + 1, 0);
        vector<long long> prefixX(m + 1, 0);
        vector<int> nonZeroCount(m + 1, 0);
        vector<long long> power10(m + 1, 1);

        for (int i = 1; i <= m; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < m; i++) {
            int digit = s[i] - '0';
            prefixDigitSum[i + 1] = prefixDigitSum[i] + digit;

            if (digit != 0) {
                prefixX[i + 1] = (prefixX[i] * 10 + digit) % MOD;
                nonZeroCount[i + 1] = nonZeroCount[i] + 1;
            } else {
                prefixX[i + 1] = prefixX[i];
                nonZeroCount[i + 1] = nonZeroCount[i];
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            long long sum = prefixDigitSum[r + 1] - prefixDigitSum[l];
            int k = nonZeroCount[r + 1] - nonZeroCount[l];
            
            long long x = (prefixX[r + 1] - (prefixX[l] * power10[k]) % MOD + MOD) % MOD;

            res[i] = (x * (sum % MOD)) % MOD;
        }

        return res;
    }
};