class Solution {
public:
    bool isSubsetPossible(vector<int> &arr, int n, int sum) {
	bool t[n + 1][sum + 1]; // DP - matrix
	for (int i = 0; i <= n; i++) { 
		for (int j = 0; j <= sum; j++) { 
			if (i == 0)
				t[i][j] = false;
			if (j == 0) 
				t[i][j] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j) 
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
			else 
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum]; 
}
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        int n=arr.size();
	for (int i = 0; i < n; i++) 
		sum += arr[i];

	if (sum % 2 != 0) 
		return false;

	  return isSubsetPossible(arr, n, sum / 2);
    }
};