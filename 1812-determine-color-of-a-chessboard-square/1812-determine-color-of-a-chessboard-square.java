class Solution:
    def squareIsWhite(self, a: str) -> bool:
        return ord(a[0]) % 2 != int(a[1]) % 2