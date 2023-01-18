class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
      int sum=0,max_sum=INT_MIN;
       int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
           // cout<<" a = "<<a<<" curMax : "<<curMax<<endl;
            maxSum = max(maxSum, curMax);
           // cout<<" a = "<<a<<" maxSum : "<<maxSum<<endl;
            curMin = min(curMin + a, a);
            //cout<<" a = "<<a<<" curMin : "<<curMin<<endl;
            minSum = min(minSum, curMin);
            //cout<<" a = "<<a<<" minSum : "<<minSum<<endl;
            total += a;
           // cout<<" a = "<<a<<" total : "<<total<<endl;
            //cout<<endl;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;   
    }
};