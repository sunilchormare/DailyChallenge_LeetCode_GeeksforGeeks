class Solution:
    def countWays(self, A: List[List[int]]) -> int:
        pre = -1
        res = 0
        for a,b in sorted(A):
            res += pre < a
            pre = max(pre, b)
        return pow(2, res, 10**9+7)
        