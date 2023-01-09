class Solution {
    public int maxDistance(int[] position, int m) {
        int n = position.length;
        Arrays.sort(position);
        int left = 0, right = position[n-1] - position[0];
        while (left < right) {
            int mid = right - (right - left)/2;
            if (count(mid, position) >= m)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
    
    private int count(int minDist, int[] position) {
        int ans = 1, cur = position[0];
        for (int i = 1; i < position.length; i++) {
            if (position[i] - cur >= minDist) {
                ans++;
                cur = position[i];
            }
        }
        return ans;
    }
}