class Solution {
public:
    map<int,int> mpp ;
    int sum(int num){
        int s = 0 ;
        while(num){
            s += num % 10 ;
            num /= 10 ;
        }
        return s ;
    }
    int countLargestGroup(int n) {
        for(int i = 1 ; i <= n ; ++i ) ++mpp[sum(i)] ;
        
        int maxi = 0 ;
        for(auto &x : mpp) maxi = max(maxi,(int)x.second) ;
        
        int ans = 0 ;
        for(auto &x : mpp) ans += ((int)x.second == maxi) ;
        return ans ;
        
        
    }
};