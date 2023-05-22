class Solution {
  public boolean canThreePartsEqualSum(int[] A) {
        if(A == null || A.length == 0) return true;
        
        int n = A.length;
        // get the total sum
        int sum = 0;
        for(int num : A) sum += num;
        if(sum % 3 != 0) return false;
        
        int average = sum / 3;
        int[] prefixSum = new int[n];
        boolean flag1 = false;
        boolean flag2 = false;
        for(int i = 0; i < n; i++){
            if(i == 0) prefixSum[0] = A[0];
            else prefixSum[i] = prefixSum[i - 1] + A[i];
            if(prefixSum[i] == average && flag1 == false) flag1 = true;
            else if(prefixSum[i] == 2*average && flag1 == true && flag2 == false && i <= n - 2) return true;
        }
        
        return false;
    }
}