class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
     int n = arr.size(),sum = 0;;
    
    for(int i=0; i<k; i++)
        sum+=arr[i];
        cout<<"sum :" <<sum;
        
    int maxi = sum; 
    for(int i=0; i<k; i++)
    {
        sum = sum - arr[k-i-1] + arr[n-i-1];
        maxi = max(maxi, sum);
    }
    return maxi;    
    }
};