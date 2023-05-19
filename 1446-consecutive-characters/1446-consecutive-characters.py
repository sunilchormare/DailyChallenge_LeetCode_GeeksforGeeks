class Solution:
    def maxPower(self, s):
        return max(len(list(b)) for a, b in itertools.groupby(s))