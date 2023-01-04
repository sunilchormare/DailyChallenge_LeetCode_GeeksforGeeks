class Solution:
    def longestPalindrome(self, s: str) -> int:
        freq = [0]*128;
        for c in s:freq[ord(c)]+=1
        OddGroup = 0
        for i in freq: OddGroup += i & 1
        return len(s) - OddGroup + (OddGroup > 0) 
        