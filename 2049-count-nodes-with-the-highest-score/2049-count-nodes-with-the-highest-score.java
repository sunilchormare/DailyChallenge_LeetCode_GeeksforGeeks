class Solution {
    long dfs(List<List<Integer>> al, long[] s, int i) {
    long prod = 1, sum = 1;
    for (int j : al.get(i)) {
        long cnt = dfs(al, s, j);
        prod *= cnt;
        sum += cnt;
    }
    s[i] = prod * (Math.max(1, al.size() - sum));
    return sum;
}    
public int countHighestScoreNodes(int[] p) {
    List<List<Integer>> al = new ArrayList<>();
    for (int i = 0; i < p.length; ++i)
        al.add(new ArrayList<Integer>());         
    long[] s = new long[p.length];
    for (int i = 1; i < p.length; ++i)
        al.get(p[i]).add(i);
    dfs(al, s, 0);
    long max_val = Arrays.stream(s).max().getAsLong();
    return (int)Arrays.stream(s).filter(v -> v == max_val).count();
}
}