class Solution {
public:
    int shortestSubarray(vector<int>& nums, int targetSum) {
        int n = nums.size();

        // Size is n+1 to handle subarrays starting from index 0
        vector<long long> prefixSums(n + 1, 0);

        // Calculate prefix sums
        for (int i = 1; i <= n; i++) {
            prefixSums[i] = prefixSums[i - 1] + nums[i - 1];
        }

        deque<int> candidateIndices;

        int shortestSubarrayLength = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // Remove candidates from front of deque where subarray sum meets
            // target
            while (!candidateIndices.empty() &&
                   prefixSums[i] - prefixSums[candidateIndices.front()] >=
                       targetSum) {
                // Update shortest subarray length
                shortestSubarrayLength =
                    min(shortestSubarrayLength, i - candidateIndices.front());
                candidateIndices.pop_front();
            }

            // Maintain monotonicity by removing indices with larger prefix sums
            while (!candidateIndices.empty() &&
                   prefixSums[i] <= prefixSums[candidateIndices.back()]) {
                candidateIndices.pop_back();
            }

            // Add current index to candidates
            candidateIndices.push_back(i);
        }

        // Return -1 if no valid subarray found
        return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
    }
};