class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        c = collections.Counter((A + " " + B).split())
        return [w for w in c if c[w] == 1]