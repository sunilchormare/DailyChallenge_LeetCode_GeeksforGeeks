class Solution:
    def reachingPoints(self, sx, sy, tx, ty):
        while sx < tx and sy < ty:
            tx, ty = tx % ty, ty % tx
        return sx == tx and sy <= ty and (ty - sy) % sx == 0 or \
               sy == ty and sx <= tx and (tx - sx) % sy == 0
        