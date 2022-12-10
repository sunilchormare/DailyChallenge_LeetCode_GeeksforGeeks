class Solution {
    public int twoEggDrop(int n) {
        int res = 1;
    while (n - res > 0)
        n -= res++;
    return res;  
    }
}