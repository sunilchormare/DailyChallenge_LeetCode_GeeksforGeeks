class Solution {
    public String greatestLetter(String s) {
       
        String ans = "";
       	boolean[] uppercase = new boolean[26];
		boolean[] lowercase = new boolean[26];

		for (char c : s.toCharArray()) {

			if (Character.isLowerCase(c))
				lowercase[c-'a'] = true;

			if (Character.isUpperCase(c))
				uppercase[c-'A'] = true;
		}

		for (int i = 25; i >= 0; i--) {

			if (uppercase[i] && lowercase[i])
				return (char)(i + 'A') + "";
		}
        return ans;
            
    }
}
