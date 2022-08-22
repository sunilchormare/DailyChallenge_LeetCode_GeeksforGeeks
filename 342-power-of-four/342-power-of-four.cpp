class Solution {
public:
    bool isPowerOfFour(int n) {
            //if(n==1) return true;
      //   for(long i=2;i<=n/2;i+2)
      //   {
      //       if(pow(4,i)==n)
      //           return true;
      //   }
      // return false;
        if(n>1) while(n%4==0) n /= 4;
      return n==1;  
    }
};