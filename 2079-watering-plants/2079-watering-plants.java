class Solution {
    public int wateringPlants(int[] p, int capacity) {
        int res = 0, can = capacity;
    for (int i = 0; i < p.length; ++i) {
        if (can < p[i]) {
            res += i * 2;
            can = capacity;
        }
        can -= p[i];
    }
    return res + p.length;    
    }
}