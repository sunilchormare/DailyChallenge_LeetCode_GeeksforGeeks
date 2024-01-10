class Solution {
   
   int max = 0;
   
   public int maxUniqueSplit(String s) {
       backtracking(s, 0, new HashSet<>());
       return max;
   }
   
   private void backtracking(String s, int start, Set<String> set) {
       if (start == s.length()) {
           max = Math.max(max, set.size());
       } else {
           for (int i = start + 1; i <= s.length(); i++) {
               String string = s.substring(start, i);
               if (set.add(string)) {
                   backtracking(s, i, set);
                   set.remove(string);
               }
           }
       }
   }
}