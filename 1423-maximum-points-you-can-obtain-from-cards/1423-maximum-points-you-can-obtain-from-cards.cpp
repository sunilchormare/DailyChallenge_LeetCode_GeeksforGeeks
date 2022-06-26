class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
     int n = arr.size(),sum = 0;;
    
    for(int i=0; i<k; i++)
        sum+=arr[i];
        // cout<<"sum :" <<sum<<endl;
        
    int maxi = sum; 
    for(int i=0; i<k; i++)
    {
        sum = sum - arr[k-i-1] + arr[n-i-1];
        // cout<<"i = "<<i<<endl<<" arr[k-i-1] : "<<arr[k-i-1]<<" arr[n-i-1] : "<<arr[n-i-1]<<" sum : "<<sum<<endl;
        maxi = max(maxi, sum);
        // cout<<" maxi : "<<maxi<<endl;
    }
    return maxi;    
    }
};