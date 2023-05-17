class Solution {
 public int waysToMakeFair(int[] A) {
        int res = 0, n = A.length, left[] = new int[2], right[] = new int[2];
        for (int i = 0; i < n; i++)
            right[i%2] += A[i]; 
        for (int i = 0; i < n; i++) {
            right[i%2] -= A[i];
            if (left[0]+right[1] == left[1]+right[0]) res++;
            left[i%2] += A[i];
        }
        return res;
    }
}