class Solution {
      public int largestSubmatrix(int[][] matrix) {
        int[] len=new int[matrix[0].length];
        int res=0;
        for(int i=0;i<matrix.length;i++) {
            for(int j=0;j<matrix[i].length;j++) {
                if(matrix[i][j]==0) len[j]=0;
                else len[j]++;
            }
            int[] tmp=len.clone();
            Arrays.sort(tmp);
            for(int l=1;l<=tmp.length;l++) {
                res=Math.max(res, l*tmp[tmp.length-l]);
            }
        }
        return res;
    }
}