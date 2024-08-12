class Solution {
    public int maximumLengthSubstring(String s) {
        int max = 0,
    len = s.length(),
    left = 0,
    right = 0;
Map<Character,Integer> map = new HashMap<>();

while(right < len){
    char end = s.charAt(right);

    map.put(end, map.getOrDefault(end,0) + 1);
    while(map.get(end) == 3){
        char begin = s.charAt(left++);
        map.put(begin, map.getOrDefault(begin,0)-1);
    }

    max = Math.max(max, right - left + 1);
    right++;
}

return max;
    }
}