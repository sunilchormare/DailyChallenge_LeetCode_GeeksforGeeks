class Solution {
public:
    int numWays(string s) {
        long n=s.size();
        vector<int>c(n,0);
        long sum=0,zero=0;
        
        for(int i=0;i<n;i++){
            sum+=(s[i]-'0');
            c[i]=sum;
            if(s[i]-'0'==0)zero++;
        }
        
        if(c[n-1]%3!=0)return 0;
        if(zero==n){
            return (n-1)*(n-2)/2%(1000000007);
        }
        
        long dif=c[n-1]/3;
        long l=0,r=0;
        for(int i=0;i<n;i++){
            if(c[i]==dif)l++;
            if(c[n-1]-c[i]==dif)r++;
        }
        
       return l*r%(1000000007); 
    }
};