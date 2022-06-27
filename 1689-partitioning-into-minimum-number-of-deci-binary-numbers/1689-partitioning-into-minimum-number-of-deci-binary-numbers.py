class Solution:
    def minPartitions(self, n: str) -> int:
        maxi=0;
        for i in n:
            maxi=max(maxi,ord(i)-ord('0'));
        return maxi;
        