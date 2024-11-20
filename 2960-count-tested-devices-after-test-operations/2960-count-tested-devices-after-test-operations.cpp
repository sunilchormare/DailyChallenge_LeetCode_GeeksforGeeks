class Solution {
public:
    int countTestedDevices(vector<int>& bP) {
        int tested=0;
        int n=bP.size();
        
        for(int i=0;i<n;++i)
        {
            if(bP[i]>0)
            {
                tested++;
                int j=i+1;
                while(j<n)
                {
                    bP[j]=max(0,bP[j]-1);
                    j++;
                }
                
            }
            
        }
        
        return tested;
    }
};