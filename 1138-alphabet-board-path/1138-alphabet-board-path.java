class Solution {
    public String alphabetBoardPath(String target) {
      StringBuilder path = new StringBuilder();
        for (int i = 0, r = 0, c = 0; i < target.length(); i++) {
            int p = target.charAt(i) - 'a', r1 = p / 5, c1 = p % 5;
            for (; r > r1; r--) path.append("U");
            for (; c > c1; c--) path.append("L");
            for (; c < c1; c++) path.append("R");
            for (; r < r1; r++) path.append("D");
            path.append("!");
        }
        return path.toString();
    }
}