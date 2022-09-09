class Solution {
    public int numberOfWeakCharacters(int[][] p) {
             int n = p.length;
        int count = 0;
        
        Arrays.sort(p, (a, b) -> (b[0] == a[0]) ? (a[1] - b[1]) : b[0] - a[0]);
        
        int max = 0;
        for (int i = 0; i < n; i++) {
            
            if (p[i][1] < max) {
                count++;
            }
            max = Math.max(max, p[i][1]);
        }
        return count;
    }
}