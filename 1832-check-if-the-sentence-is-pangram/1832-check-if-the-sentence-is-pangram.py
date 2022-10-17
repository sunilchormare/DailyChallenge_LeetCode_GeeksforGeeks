class Solution {
    public boolean checkIfPangram(String sentence) {
//         for (int i = 0; i < 26; ++i) {
//             char currChar = (char)('a' + i);

//             if (sentence.indexOf(currChar) == -1)
//                 return false;
//         }
    
//         return true;
         Set<Character> seen = new HashSet<>();
        
        // Iterate over 'sentence' add every letter to 'seen'.
        for (char currChar : sentence.toCharArray())
            seen.add(currChar);
        
        // If the size of 'seen' is 26, then 'sentence' is a pangram.
        return seen.size() == 26;
    }
}