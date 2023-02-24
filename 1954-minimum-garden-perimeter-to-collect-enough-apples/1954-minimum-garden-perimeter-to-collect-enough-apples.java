class Solution {
    public long minimumPerimeter(long x) {
         long l = 1,  r = 100000, m;
        while (l < r) {
            m = (l + r) / 2;
            if (m * m * m * 4 + m * m * 6 + m * 2 >= x)
                r = m;
            else
                l = m + 1;
        }
        return l * 8;
    }
}