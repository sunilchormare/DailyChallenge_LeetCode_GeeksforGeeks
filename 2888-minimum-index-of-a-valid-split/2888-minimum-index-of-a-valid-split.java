class Solution {
  public int minimumIndex(List<Integer> nums) {
    var map = new HashMap<Integer, Integer>();
    map.put(0, 0);
    int max = 0, m = nums.size();
    
    for (var n : nums) {
      map.put(n, map.getOrDefault(n, 0) + 1);
      
      if (map.get(n) > map.get(max))
        max = n;
    }
    var freq = 0;
    for (var i=0; i<m; i++) {
      if (nums.get(i) == max) freq++;
      
      if (freq * 2 > i+1 && (map.get(max) - freq) * 2 > (m-i-1))
        return i;
    }
    return -1;
  }
}