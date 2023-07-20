public class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int[] result = new int[k];
        for (int i = Math.max(0, k - nums2.length); i <= Math.min(nums1.length, k); i++) {
            int j = k - i;
            int[] part1 = findMax(nums1, i);
            int[] part2 = findMax(nums2, j);
            int[] cand = merge(part1, part2);
            if (greater(cand, 0, result, 0)) {
                result = cand;
            }
        }
        return result;
    }

    private boolean greater(int[] nums1, int start1, int[] nums2, int start2) {
        while (start1 < nums1.length && start2 < nums2.length && nums1[start1] == nums2[start2]) {
            start1++;
            start2++;
        }
        return start2 == nums2.length || (start1 < nums1.length && nums1[start1] > nums2[start2]);
    }

    private int[] merge(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length + nums2.length];
        int i = 0, j = 0, k = 0;
        while (i < nums1.length && j < nums2.length) {
            if (greater(nums1, i, nums2, j)) {
                result[k++] = nums1[i++];
            } else {
                result[k++] = nums2[j++];
            }
        }
        while (i < nums1.length) {
            result[k++] = nums1[i++];
        }
        while (j < nums2.length) {
            result[k++] = nums2[j++];
        }
        return result;
    }

    private int[] findMax(int[] nums, int k) {
        int[] result = new int[k];
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            while (j > 0 && result[j - 1] < nums[i] && j + nums.length - i > k) {
                j--;
            }
            if (j < k) {
                result[j++] = nums[i];
            }
        }
        return result;
    }
}