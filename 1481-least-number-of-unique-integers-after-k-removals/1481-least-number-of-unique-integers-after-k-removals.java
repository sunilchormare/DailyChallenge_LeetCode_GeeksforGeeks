class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int n : arr) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        
        List<Integer> values = new ArrayList<>(map.values());
        Collections.sort(values);
        
        int count = 0;
        for(int n : values) {
            k -= n;
            
            if (k < 0)
                break;
            else 
                count++;
        }
        
        return map.keySet().size() - count; 
    }
}