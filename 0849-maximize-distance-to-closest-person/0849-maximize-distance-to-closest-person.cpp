class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
     
        int l=-1,n=seats.size();
        int maxDis=0;
        for(int i=0;i<n;++i)
        {
            if(seats[i]==1)
            {
                if(l==-1)
                    maxDis=i;
                else
                    maxDis=max(maxDis,(i-l)/2);
                l=i;
            }
        }
        if(seats[n-1]==0)
            maxDis=max(maxDis,n-1-l);
        return maxDis;
    }
};