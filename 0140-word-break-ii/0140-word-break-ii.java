class Solution {
     public List<String> wordBreak(String s, List<String> wordDict) {
    List<String> result = new ArrayList<>();
    HashSet<String> set = new HashSet<>(wordDict);
    helper(s,set, 0, 0, "", List.of(),result);
    return result;
  }

  public void helper(String s, Set<String> set, int start, int end, String word, List<String> words, List<String> res){
    System.out.println(String.format("start: %d y end: %d", start, end));
    if(word.equals(s)){
      res.add(String.join(" ", words));
    }
    else if(start >= s.length() || end > s.length()) return;
    else{
      String prefix = s.substring(start, end);
      if(set.contains(prefix)){
        ArrayList<String> temp = new ArrayList<>(words);
        temp.add(prefix);
        helper(s, set, end, end, word + prefix, temp, res);
        helper(s, set, start, end + 1, word, new ArrayList<>(words),res);
      }else{
        helper(s, set, start, end + 1, word, new ArrayList<>(words), res);
      }
    }
  }
}