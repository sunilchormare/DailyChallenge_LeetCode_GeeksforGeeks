class Solution:
    def minOperations(self, A: List[int]) -> int:
        return sum(bin(a).count('1') for a in A) + len(bin(max(A))) - 3