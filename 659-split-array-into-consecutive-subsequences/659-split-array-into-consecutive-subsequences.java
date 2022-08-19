class Solution {
    public boolean isPossible(int[] nums) {
       Map<Integer, Integer> left = new HashMap<>(), end = new HashMap<>();
    for (int i : nums) left.put(i, left.getOrDefault(i,0) + 1);
    for (int i : nums) {
        if (left.get(i) == 0) continue;
        else if (end.getOrDefault(i,0) > 0) {
            end.put(i, end.get(i) - 1);
            end.put(i+1, end.getOrDefault(i+1,0) + 1);
        }   
        else if (left.getOrDefault(i+1,0) > 0 && left.getOrDefault(i+2,0) > 0) {
            left.put(i+1, left.get(i+1) - 1);
            left.put(i+2, left.get(i+2) - 1);
            end.put(i+3, end.getOrDefault(i+3,0) + 1);
        }
        else 
            return false;
        left.put(i, left.get(i) - 1);
    }
    return true;
    }
}