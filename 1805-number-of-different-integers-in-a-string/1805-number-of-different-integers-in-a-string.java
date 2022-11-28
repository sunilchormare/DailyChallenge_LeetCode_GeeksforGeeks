class Solution {
    public int numDifferentIntegers(String w) {
       var s = new HashSet<String>(Arrays.asList(""));
    int i = 0;
    for (int j = 0; j < w.length(); ++j) {
        if (Character.isDigit(w.charAt(j)))
            i += i < j && w.charAt(i) == '0' ? 1 : 0;
        else {
            s.add(w.substring(i, j));
            i = j + 1;
        }
    }
    s.add(w.substring(i));        
    return s.size() - 1;   
    }
}