class Solution:
     def maxRunTime(self, n, A):
        A.sort()
        su = sum(A)
        while A[-1] > su / n:
            n -= 1
            su -= A.pop()
        return int(su / n)
        