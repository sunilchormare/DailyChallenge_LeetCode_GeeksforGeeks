class Solution {
public:
  long long maximumSubarraySum(vector<int>& A, int k) {
    unordered_map<int, int> mp;
    long mx = 0, sum = 0;
    for (int i = 0; i < size(A); i++){
        sum += A[i];
        mp[A[i]]++;

        if (i >= k - 1){
            if (mp.size() == k) mx = max(mx, sum);
            sum -= A[i - k + 1];
            if (--mp[A[i - k + 1]] == 0) mp.erase(A[i - k + 1]);
        }
    }
    return mx;
}
};