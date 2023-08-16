class Solution:
     def reinitializePermutation(self, n):
        res, i = 0, 1
        while res == 0 or i > 1:
            i = i * 2 % (n - 1)
            res += 1
        return res
        