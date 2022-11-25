class Solution {
public:
    
//     int helper(int i,int prev,vector<int>&arr, int n)
//     {
//         if(i==n) return 0;
//         int len=0+helper(i+1,prev,arr,n);
//         if(arr[i]>arr[prev]||prev==-1)
//              len=max(len,1+helper(i+1,i,arr,n));
            
//      return len;
//     }
    int lengthOfLIS(vector<int>& arr) {
         int n=arr.size();
        int lis[n]; 

	lis[0] = 1; 

	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	} 

	return *max_element(lis, lis+n); 
        
        //return helper(0,-1,arr,n); 
    }
};