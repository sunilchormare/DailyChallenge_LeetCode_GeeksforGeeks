class Solution:
    def numTimesAllBlue(self, A: List[int]) -> int:
        right = res = 0
        for i, a in enumerate(A, 1):
            right = max(right, a)
            res += right == i
        return res