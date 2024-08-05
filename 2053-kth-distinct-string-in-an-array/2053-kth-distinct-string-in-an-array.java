class Solution {

    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> frequencyMap = new HashMap<>();

        // First pass: Populate the frequency map
        for (String str : arr) {
            frequencyMap.put(str, frequencyMap.getOrDefault(str, 0) + 1);
        }

        // Second pass: Find the k-th distinct string
        for (String str : arr) {
            // Check if the current string is distinct
            if (frequencyMap.get(str) == 1) {
                k--;
            }
            // When k reaches 0, we have found the k-th distinct string
            if (k == 0) {
                return str;
            }
        }

        return "";
    }
}