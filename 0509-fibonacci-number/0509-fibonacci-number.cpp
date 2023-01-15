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
        

        // if(n <= 1)
        //     return n;
        // else
        //     return fib(n - 1) + fib(n - 2);
        //    int[] fib_cache = new int[31];
	
	
      if(n==0)
            return 0;
        
        vector<int> dp(n+1);
        
        //Assign starting elements -> 0,1
        dp[0]=0;dp[1]=1;
        
        //Run loop till n
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        
        //return the F(n) value
        return dp[n];
            
    }
};