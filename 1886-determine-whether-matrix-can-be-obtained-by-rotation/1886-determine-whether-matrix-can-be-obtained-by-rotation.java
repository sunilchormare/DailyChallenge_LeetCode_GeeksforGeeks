class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
    
    int len = mat.length;
   
   //90 degree * 4 = 360degree, we can rotate 90 degree & check whether it matches the target 
    for(int i=0; i<4; i++){
        if(Arrays.deepEquals(mat,target))
            return true;
        rotate90Degrees(mat,len);
    }
    return false;
}

public void rotate90Degrees(int[][]mat, int len){
    
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            if(i!=j){
            int temp=0;
            temp = mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
            }
        }
    }
    
    for(int i=0;i<len;i++){
        for(int j=0;j<len/2;j++){
            int temp=0;
            temp=mat[i][j];
            mat[i][j]=mat[i][len-1-j];
            mat[i][len-1-j]=temp;
        }
    }
    
}
}