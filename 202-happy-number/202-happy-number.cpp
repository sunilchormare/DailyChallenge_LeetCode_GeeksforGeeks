class Solution {
    public int digitSquare(int n)
    {
        int sum=0,tem;
        while(n!=0)
        {
            tem=n%10;
            sum+=(tem*tem);
            n=n/10;
        }
        return sum;
         
    }
    public boolean isHappy(int n) {
     int slow=n,fast=n;
        do{
            slow=digitSquare(slow);
            fast=digitSquare(fast);
            fast=digitSquare(fast);
            if(fast==1) return true;
        }while(slow!=fast);
        
        return false;
    }
}