class Solution {
    public int minDeletionSize(String[] A) {
        int n = A.length, m = A[0].length();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n-1; j++){
                if(A[j].charAt(i) > A[j+1].charAt(i)){
                    count++;
                    break;
                }
                    
            }
            
        }
        return count;
    }
}