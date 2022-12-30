class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
     vector<long long> ind(primes.size(),0);
        vector<long long> res;
        unordered_map<long long,int> m;
        res.push_back(1);
        while(res.size()<n)
        {
            long long t=INT_MAX;
            int p=0;
            for(int i=0;i<primes.size();i++)
            {
                if(t>primes[i]*res[ind[i]])
                {
                    t=primes[i]*res[ind[i]];
                    p=i;
                }
            }
            ind[p]++;
            if(m.find(t)==m.end())
            {
                res.push_back(t);
                m[t]=1;
            }
        }
        return res[n-1];
    }
};