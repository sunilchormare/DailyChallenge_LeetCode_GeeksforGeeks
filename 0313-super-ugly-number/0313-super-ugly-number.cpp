class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      vector<int> vec(n,0);
        vec[0]=1;
        int total_primes=primes.size();
        vector<int> pointers(total_primes,0);
        for(int i=1;i<n;i++){
            long long mn=INT_MAX;
            for(int j=0;j<total_primes;j++){
                mn=min(mn,(long long)primes[j]*(long long)vec[pointers[j]]);
                
            }
            vec[i]=mn;
            for(int j=0;j<total_primes;j++){
                if(mn == (long long)primes[j] * (long long)vec[pointers[j]])
                {
                    pointers[j]++;
                }
            }
        }
        return vec[n-1];
    }
};