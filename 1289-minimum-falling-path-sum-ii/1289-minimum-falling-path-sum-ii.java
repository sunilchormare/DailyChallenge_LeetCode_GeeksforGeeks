class Solution {
    public int minFallingPathSum(int[][] arr) {
        for (int rowIndex = 1; rowIndex < arr.length; rowIndex++) {
            PriorityQueue<Integer> priorityQueue = new PriorityQueue();
            for (int colIndex = 0; colIndex < arr[0].length; colIndex++) {
                priorityQueue.offer(arr[rowIndex - 1] [colIndex]);
            }
            int firstSmallest = priorityQueue.poll();
            int secondSmallest = priorityQueue.poll();
            for (int colIndex = 0; colIndex < arr[0].length; colIndex++) {
                if (arr[rowIndex - 1] [colIndex] == firstSmallest) {
                    arr[rowIndex] [colIndex] = arr[rowIndex] [colIndex] + secondSmallest;
                } else {
                    arr[rowIndex] [colIndex] = arr[rowIndex] [colIndex] + firstSmallest;
                }
            }
        }
        int result = Integer.MAX_VALUE;
        for (int colIndex = 0; colIndex < arr[0].length; colIndex++) {
            result = Math.min(result, arr[arr.length - 1][colIndex]);
        }
        return result;
    }
}