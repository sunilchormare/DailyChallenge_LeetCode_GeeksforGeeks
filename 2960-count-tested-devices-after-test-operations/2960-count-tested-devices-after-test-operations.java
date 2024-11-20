class Solution {
    public int countTestedDevices(int[] A) {
       int k = 0;
        for (int a : A)
            k += a > k ?  1 : 0;
        return k;
    }
}