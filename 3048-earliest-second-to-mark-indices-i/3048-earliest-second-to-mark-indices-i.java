class Solution {
    public int earliestSecondToMarkIndices(int[] nums, int[] changeIndices) {
        int n = nums.length;
        int[] changeIndicesAdjusted = Arrays.stream(changeIndices).map(index -> index - 1).toArray();
        int low = 0, high = changeIndices.length - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (isPossible(nums, changeIndicesAdjusted, mid)) high = mid;
            else low = mid + 1;
        }
		// Delay Marking as Much as Possible
        return isPossible(nums, changeIndicesAdjusted, low) ? low + 1 : -1;
    }

	// isPossible method is called to check if it's possible to mark all indices in s seconds while delaying marking as much as possible.
    private boolean isPossible(int[] nums, int[] changeIndices, int s) {
        int n = nums.length;
        int[] last = new int[n];
        Arrays.fill(last, -1);
        for (int i = 0; i <= s; i++) { // Latest Point to Mark an Index
            last[changeIndices[i]] = i;
        }
        int marked = 0, operations = 0;
        for (int i = 0; i <= s; i++) { // Store Decrement Operations
            if (i == last[changeIndices[i]]) {
                if (nums[changeIndices[i]] > operations) return false;
                operations -= nums[changeIndices[i]];
                marked++;
            } else {
                operations++;
            }
        }
        return marked == n;
    }
}