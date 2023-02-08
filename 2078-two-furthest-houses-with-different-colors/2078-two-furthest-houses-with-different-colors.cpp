class Solution {
public:
    int maxDistance(vector<int>& c) {
     int n=c.size();
     int maxi=0;
     for(int i=0;i<n;++i)
     {
         if(c[i]!=c[0])
            maxi=max(maxi,i);
     }
    for(int i=n-2;i>=0;--i)
     {
         if(c[i]!=c[n-1])
            maxi=max(maxi,n-1-i);
     }
    return maxi;
    }
};