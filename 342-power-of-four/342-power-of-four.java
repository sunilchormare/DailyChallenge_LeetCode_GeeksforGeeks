class Solution {
    public boolean isPowerOfFour(int num) {
      //     if(n>1) 
      //       while(n%4==0) 
      //           n /= 4;
      // return n==1;  
        
        return (num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0);
    }
}