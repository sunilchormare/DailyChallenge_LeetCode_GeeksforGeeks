class Solution {
public:
    
    int digitSum(int num)
    {
        int sum=0;
        if(num<10) return num;
        
        while(num>0)
        {
            sum+=num%10;
            num/=10;
            
        }
        
        return sum;
    }
        
    
    int countEven(int num) {
      
        int res=0;
        for(int i=1;i<=num;++i)
        {
            if(digitSum(i)%2==0)
                res++;
            
        }
            
        return res;
    }
};