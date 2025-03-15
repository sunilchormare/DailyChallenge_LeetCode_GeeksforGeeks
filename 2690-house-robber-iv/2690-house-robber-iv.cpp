class Solution {
public:
     int help(vector<int> &a, int k, int i, vector<int> &dp1){
        if(i>=a.size()){
            return 0;
        }
    if(dp1[i]!=-1){
        return dp1[i];
    }
        int take=0;
        int nt=help(a,k,i+1,dp1);
        
        if(a[i]<=k){
            return dp1[i]= max(help(a,k,i+2,dp1)+1,nt);
        }
        return dp1[i]= nt;
    }
    
    bool check(vector<int> &a, int k, int req){
        vector<int> dp1(a.size());
        for(int i=0;i<a.size();i++){
            dp1[i]=-1;
        }
        int maxi=help(a,k,0,dp1);

        return maxi>=req;
    }
    int minCapability(vector<int>& nums, int k) {
         int s=0;
        int e=1000000000;
        while(s+1<e){
            int m=s+(e-s)/2;
            if(check(nums,m,k)){
                e=m;
            }
            else{
                s=m;
            }
            
        }
        
        return e;
    }
};