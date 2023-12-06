class Solution {
    public int minGroupsForValidAssignment(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int n : nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        
        int min = nums.length;
        for(int v : map.values()) {
            min = Math.min(min, v);
        }

        for(int size = min; size >= 1; --size) {
            int numGroups = groupify(map, size); 
            if(numGroups > 0) return numGroups;
        }
        
        return nums.length;
    }
    
    private int groupify(Map<Integer, Integer> map, int size) {
        int groups = 0;
        int next = size + 1;
        
        for(int value : map.values()) {
            int numGroups = value / next;
            int remaining = value % next;

            if(remaining == 0) {
                groups += numGroups;
            }
            // So far we have divided things into numGroups + 1 groups
            // where the first numGroups have size + 1 elements
            // and the last group has has remaining = {1 ... size} elements.
            //
            // In order to make this grouping valid, each group out of numGroups
            // can potentially give 1 element to the last group.
            //
            // The idea is that a subset of those groups should be able to give 1 element 
            // each to the last group so that the last group also has size elements. 
            //
            // In other words, in order for the last group to have size elements, 
            // size - remaining groups have to contribute 1 element each.
            // 
            // So there must be at least size - remaining groups of size + 1 elements.
            else if(numGroups >= size - remaining) {
                groups += numGroups + 1;
            } 
            else {
                return 0;
            }
        }
        return groups;
    }
}