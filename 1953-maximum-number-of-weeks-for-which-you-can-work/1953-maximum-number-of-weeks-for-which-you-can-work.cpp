class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int i,j,maxi=-1,n=milestones.size();
  
    	long long sum=0;
    	for(i=0;i<n;i++)
    	{
    		maxi=max(maxi, milestones[i]);
    		sum+=milestones[i];
    	}
		
    	
    	long long x=sum-maxi;
    	
    	if(maxi-x>1)
    		return sum-(maxi-x-1);
    	return sum;
    }
};