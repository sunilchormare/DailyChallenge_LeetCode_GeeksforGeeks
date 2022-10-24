class Solution {
    public int maxLength(List<String> arr) {
         return process(arr, "", 0);
    }
    int process(List<String> arr, String soFar, int index) {
        if (index > arr.size()) return 0;
        Set<Character> set = new HashSet<>();
        for(char c: soFar.toCharArray()) {
            if(set.contains(c)) return 0;
            set.add(c);
        }
        int max = soFar.length();
        for(int i = index; i < arr.size(); i++) {
            max = Math.max(max, process(arr, soFar + arr.get(i), i + 1));
        }
        return max;
    }
}