class Solution:
    def transpose(self, M: List[List[int]]) -> List[List[int]]:
        return zip(*M)