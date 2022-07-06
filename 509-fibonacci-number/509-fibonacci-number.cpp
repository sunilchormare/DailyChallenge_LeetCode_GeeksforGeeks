class Solution {
public:
    int fib(int n) {
//          if(n==0) return 0;
//           if(n==1||n==2) return 1;
          
//          //int f1=1,f2=1,f3=2;
//         vector<int> dp{1,1,2};
        
//         for(int i=2;i<30;++i)
//            dp[i]=dp[i-1]+dp[i-2];
          
//         return dp[n+1];
        

        if(n <= 1)
            return n;
        else
            return fib(n - 1) + fib(n - 2);
            
            
    }
};