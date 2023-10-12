class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int peak = findPeakIndex(mountainArr);
        
        if (target == mountainArr.get(peak)) return peak;
        
        int leftIndex = binarySearch(mountainArr, 0, peak - 1, target, true);
        int rightIndex = binarySearch(mountainArr, peak + 1, mountainArr.length() - 1, target, false);
        
        return leftIndex != -1 ? leftIndex : rightIndex;
    }
    
    int findPeakIndex(MountainArray arr) {
        int len = arr.length();
        int left = 0, right = len -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = arr.get(mid);
            int leftMidVal = mid > 0 ? arr.get(mid - 1) : Integer.MIN_VALUE;
            int rightMidVal = mid < len - 1 ? arr.get(mid + 1) : Integer.MAX_VALUE;
            
            if (midVal > leftMidVal && midVal > rightMidVal) return mid;
            
            if (midVal >= leftMidVal && midVal <= rightMidVal) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
    
    int binarySearch(MountainArray mountainArr, int left, int right, int target, boolean incr) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;
            
            if (target > val) {
                if (incr) {
                    left = mid + 1;  
                } else {
                    right = mid - 1;
                }
            } else { // target < val
                if (incr) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return -1;
    }
}