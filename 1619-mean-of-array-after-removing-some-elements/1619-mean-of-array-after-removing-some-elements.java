class Solution {
    public double trimMean(int[] arr) {
        int n = arr.length;
        double sum = 0d;
        Arrays.sort(arr);
        for (int i = n / 20; i < n - n / 20; ++i) {
            sum += arr[i];
        }
        return sum / (n * 9 / 10);
    }
}