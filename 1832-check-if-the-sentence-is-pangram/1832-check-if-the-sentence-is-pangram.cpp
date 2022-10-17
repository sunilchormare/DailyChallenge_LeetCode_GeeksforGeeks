class Solution {
public:
    bool checkIfPangram(string sentence) {
//       for (int i = 0; i < 26; ++i) {
//             char currChar = 'a' + i;
         
//             if (sentence.find(currChar) == string::npos)
//                 return false;
//         }
        
//         return true; 
         unordered_set<char> seen(sentence.begin(), sentence.end());
        
        // If the size of 'seen' is 26, then 'sentence' is a pangram.
        return seen.size() == 26;
    }
};