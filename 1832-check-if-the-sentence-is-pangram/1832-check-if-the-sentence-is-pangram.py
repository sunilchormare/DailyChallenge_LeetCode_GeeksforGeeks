class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        seen = set(sentence)
        return len(seen) == 26