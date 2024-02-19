class Solution {
    public int minAreaRect(int[][] points) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for(int[] point : points) {
            map.putIfAbsent(point[0], new HashSet<>());
            map.get(point[0]).add(point[1]);
        }
        int min = Integer.MAX_VALUE;
        for(int[] p : points) {
            int x = p[0];
            int y = p[1];
            for(int[] point : points) {
                int i = point[0];
                int j = point[1];
                if(i <= x || j <= y) continue;
                        if(map.get(x).contains(j) && map.get(i).contains(y)) {
                            min = Math.min(min, (j - y) * (i - x));
                    }
                }
            }
        return min == Integer.MAX_VALUE ? 0: min;
    }
}