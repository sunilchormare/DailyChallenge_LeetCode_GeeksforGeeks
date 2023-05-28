class Solution:
    def largestMerge(self, s1, s2):
        if s1 >= s2 > '':
            return s1[0] + self.largestMerge(s1[1:], s2)
        if s2 >= s1 > '':
            return s2[0] + self.largestMerge(s1, s2[1:])
        return s1 + s2
        