class Solution:
    def checkIfPangram(self, s: str) -> bool:
        # seen = set(sentence)
        # return len(seen) == 26
        return len(set(s)) == 26