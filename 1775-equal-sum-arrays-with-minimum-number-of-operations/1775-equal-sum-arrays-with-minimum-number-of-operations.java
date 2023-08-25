class Solution {
   int minOperations(int[] n1, int[] n2) {
    if (n2.length * 6 < n1.length || n1.length * 6 < n2.length)
        return -1;
    int sum1 = Arrays.stream(n1).sum(), sum2 = Arrays.stream(n2).sum();
    if (sum1 < sum2)
        return minOperations(n1, n2, sum1, sum2);
    return minOperations(n2, n1, sum2, sum1);
}
int minOperations(int[] n1, int[] n2, int sum1, int sum2) {
    int cnt[] = new int[6], diff = sum2 - sum1, res = 0;
    for (var n : n1)
        ++cnt[6 - n];
    for (var n : n2)
        ++cnt[n - 1];
    for (int i = 5; i > 0 && diff > 0; --i) {
        int take = Math.min(cnt[i], diff / i + (diff % i != 0 ? 1 : 0));
        diff -= take * i;
        res += take;
    }    
    return res;
}
}