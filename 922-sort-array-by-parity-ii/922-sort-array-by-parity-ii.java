class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int[] res = new int[A.length];
        int j = 0, k = 1;
       
        for(int i = 0; i < A.length; i++) 
        {
            if(A[i] % 2 == 0)
            {
                res[j] = A[i];
                j += 2;
            }
            else
            {
                res[k] = A[i];
                k += 2;
            }
    }
        return res;
}
}