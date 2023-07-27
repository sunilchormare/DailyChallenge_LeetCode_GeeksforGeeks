class Solution:
    def findNumOfValidWords(self, words, puzzles):
        count = collections.Counter()
        for w in words:
            if len(set(w)) > 7: continue
            m = 0
            for c in w:
                m |= 1 << (ord(c) - 97)
            count[m] += 1
        res = []
        for p in puzzles:
            bfs = [1 << (ord(p[0]) - 97)]
            for c in p[1:]:
                bfs += [m | 1 << (ord(c) - 97) for m in bfs]
            res.append(sum(count[m] for m in bfs))
        return res
        