class Solution:
       def countSubarrays(self, A, k):
        res = cur = i = 0
        for j in range(len(A)):
            cur += A[j]
            while cur * (j - i + 1) >= k:
                cur -= A[i]
                i += 1
            res += j - i + 1
        return res

        