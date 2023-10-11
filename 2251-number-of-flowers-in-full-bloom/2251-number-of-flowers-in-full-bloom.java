class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        TreeMap<Integer, Integer> difference = new TreeMap<>();
        difference.put(0, 0);
        
        for (int[] flower : flowers) {
            int start = flower[0];
            int end = flower[1] + 1;
            
            difference.put(start, difference.getOrDefault(start, 0) + 1);
            difference.put(end, difference.getOrDefault(end, 0) - 1);
        }
        
        List<Integer> positions = new ArrayList();
        List<Integer> prefix = new ArrayList();
        int curr = 0;
        
        for (int key : difference.keySet()) {
            positions.add(key);
            curr += difference.get(key);
            prefix.add(curr);
        }
        
        int[] ans = new int[people.length];
        for (int j = 0; j < people.length; j++) {
            int i = binarySearch(positions, people[j]) - 1;
            ans[j] = prefix.get(i);
        }
        
        return ans;
    }
    
    public int binarySearch(List<Integer> arr, int target) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (target < arr.get(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
}