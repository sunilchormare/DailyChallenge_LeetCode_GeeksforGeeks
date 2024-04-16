class Solution {
public:
    bool binarySearch(vector<int>& nums, vector<int>& changeIndices, int idx) {
        unordered_map<int, int> last;
        for (int i = 0; i < idx; i++) {
            last[changeIndices[i]] = i;
        }
        if (last.size() != nums.size()) return false;
        int cnt = 0; // record we can reduce how many number
        for (int i = 0; i < idx; i++) {
            // if it is last time we visit this idx, we must mark
            // so check whether this idx already reduce to zero, if not, then return false.
            if (i == last[changeIndices[i]]) {
                if (cnt < nums[changeIndices[i] - 1]) return false;
                else cnt -= nums[changeIndices[i] - 1];
            } else {
                cnt++;
            }
        }
        return true;
    }
    
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        int l = 0, r = m + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (binarySearch(nums, changeIndices, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r == m + 1? -1 : r;
    }
};