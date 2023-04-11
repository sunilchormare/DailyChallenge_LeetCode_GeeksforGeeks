class Solution:
    def removeStars(self, s: str) -> str:
        res = []
        for c in s:
            if c != '*':
                res += c
            elif res:
                res.pop()
        return ''.join(res)