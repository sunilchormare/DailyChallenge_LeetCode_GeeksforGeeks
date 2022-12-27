class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        vector<int> vac(n);
        for(int i=0;i<n;++i)
            vac[i]=capacity[i]-rocks[i];
        int count=0;
        sort(vac.begin(),vac.end());
        for(int i=0;i<n;++i)
        {
         if(vac[i]==0) count++;
         else
         {
             if(additionalRocks>=vac[i])
                 additionalRocks-=vac[i],count++;
             else
                 break;
         }
        }
        return count;
    }
};