class Solution(object):
     def maxDotProduct(self, A, B):
        n, m = len(A), len(B)
        dp = [[0] * (m) for i in xrange(n)]
        for i in xrange(n):
            for j in xrange(m):
                dp[i][j] = A[i] * B[j]
                if i and j: dp[i][j] += max(dp[i - 1][j - 1], 0)
                if i: dp[i][j] = max(dp[i][j], dp[i - 1][j])
                if j: dp[i][j] = max(dp[i][j], dp[i][j - 1])
        return dp[-1][-1]
        