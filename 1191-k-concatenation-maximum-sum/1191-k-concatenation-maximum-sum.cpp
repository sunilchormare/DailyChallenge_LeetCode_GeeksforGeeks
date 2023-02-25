class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
   int n = arr.size(),gsum = 0,sum = 0,gMax = 0,cMaxSum = 0,mod = 1e9+7;
	gsum = accumulate(arr.begin(),arr.end(),gsum);
	int maxSuf = gsum,maxPre = 0;
	for(int i = 0 ; i < n ; i++){
		sum += arr[i];
		maxSuf = max(maxSuf,gsum-sum);
		maxPre = max(sum,maxPre);
		cMaxSum = max(cMaxSum+arr[i],arr[i]);
		gMax = max(gMax,cMaxSum);
	}

	if(k == 1) return gMax;
	return (max(max(0ll,(long long)(k-2)*sum)+maxSuf+maxPre,(long long)gMax))%mod;
    }
};