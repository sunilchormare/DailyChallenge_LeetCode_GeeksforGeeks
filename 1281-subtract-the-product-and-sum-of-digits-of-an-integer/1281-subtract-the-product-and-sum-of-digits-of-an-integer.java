class Solution {
    public int subtractProductAndSum(int n) {
        int pro=1,sum=0,digit;
        while(n!=0)
        {
            digit=n%10;
            pro*=digit;
            sum+=digit;
            n/=10;
        }
        return pro-sum;
    }
}