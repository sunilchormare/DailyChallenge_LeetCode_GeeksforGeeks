class Solution {
    public long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long res = 0;
    for (int cnt = 0; cnt * cost1 <= total; ++cnt)
        res += (total - cnt * cost1) / cost2 + 1;
    return res;
    }
}