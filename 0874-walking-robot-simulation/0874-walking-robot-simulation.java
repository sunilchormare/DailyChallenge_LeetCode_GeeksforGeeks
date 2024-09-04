class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int[][] direction = {{0,1},{1,0},{0,-1},{-1,0}};
        Set<String> set = new HashSet<>();
        for (int[] o : obstacles) {
            set.add(o[0]+":"+o[1]);
        }
        int res = 0, d = 0, x = 0, y = 0;
        for (int c : commands) {
            if (c == -1) {
                d = (d+1)%4;
            } else if (c == -2) {
                d = (d-1+4)%4;
            } else {
                for (int i=1; i<=c; i++) {
                    if (!set.contains((x+direction[d][0])+":"+(y+direction[d][1]))) {
                        x += direction[d][0];
                        y += direction[d][1];
                    } else {
                        break;
                    }
                }
                res = Math.max(res, x*x + y*y);
            }
        }
        return res;
    }
}