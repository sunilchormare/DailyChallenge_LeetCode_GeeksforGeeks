// //BRUTE FORCE
// class Solution {
// public int[][] kClosest(int[][] points, int K) {
//     Arrays.sort(points, (p1, p2) -> p1[0] * p1[0] + p1[1] * p1[1] - p2[0] * p2[0] - p2[1] * p2[1]);
//     return Arrays.copyOfRange(points, 0, K);
// }
// }
//MAX HEAP
// class Solution{
// public int[][] kClosest(int[][] points, int K) {
//     PriorityQueue<int[]> pq = new PriorityQueue<int[]>((p1, p2) -> p2[0] * p2[0] + p2[1] * p2[1] - p1[0] * p1[0] - p1[1] * p1[1]);
//     for (int[] p : points) {
//         pq.offer(p);
//         if (pq.size() > K) {
//             pq.poll();
//         }
//     }
//     int[][] res = new int[K][2];
//     while (K > 0) {
//         res[--K] = pq.poll();
//     }
//     return res;
// }

// }

//QUICK SELECT
class Solution {

    public int[][] kClosest(int[][] points, int k) {

        quickSelect(points, 0, points.length - 1, k);

        int[][] result = new int[k][2];

        for (int i = 0; i < k; i++) {
            result[i] = points[i];
        }

        return result;
    }

    private void quickSelect(int[][] points, int left, int right, int k) {

        while (left <= right) {

            int pivotIndex = partition(points, left, right);

            if (pivotIndex == k - 1) {
                return;
            }

            if (pivotIndex > k - 1) {
                right = pivotIndex - 1;
            } else {
                left = pivotIndex + 1;
            }
        }
    }

    private int partition(int[][] points, int left, int right) {

        long pivotDistance =
            (long) points[right][0] * points[right][0] +
            (long) points[right][1] * points[right][1];

        int smaller = left;

        for (int i = left; i < right; i++) {

            long currentDistance =
                (long) points[i][0] * points[i][0] +
                (long) points[i][1] * points[i][1];

            if (currentDistance <= pivotDistance) {
                swap(points, smaller, i);
                smaller++;
            }
        }

        swap(points, smaller, right);

        return smaller;
    }

    private void swap(int[][] points, int i, int j) {

        int[] temp = points[i];
        points[i] = points[j];
        points[j] = temp;
    }
}