class Solution 
{
//     public List<String> letterCombinations(String digits) 
//     {    
//         List<String> result=new ArrayList<String>();
//         if(digits==null || digits.length()==0)
//         {
//             return result;
//         }       
//         String []mapping={
//             "0",
//             "1",
//             "abc",
//             "def",
//             "ghi",
//             "jkl",
//             "mno",
//             "pqrs",
//             "tuv",
//             "wxyz"
//         };
//         letterCombinationRecursive(result,digits,"",0,mapping);
//         return result;      
//     }

// private void letterCombinationRecursive(List<String> result,String digits,String current,int index,String [] mapping)
//     {
//         if(index==digits.length())
//         {
//             result.add(current);
//             return;
//         }
        
//         String letters=mapping[digits.charAt(index)-'0'];
//         for(int i=0;i<letters.length();++i)
//         {                  letterCombinationRecursive(result,digits,current+letters.charAt(i),index+1,mapping);
//         }
        
//     }
    
    public List<String> letterCombinations(String digits) {
		LinkedList<String> ans = new LinkedList<String>();
		if(digits.isEmpty()) return ans;
		String[] mapping = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		ans.add("");
		for(int i =0; i<digits.length();i++){
			int x = Character.getNumericValue(digits.charAt(i));
			while(ans.peek().length()==i){
				String t = ans.remove();
				for(char s : mapping[x].toCharArray())
					ans.add(t+s);
			}
		}
		return ans;
	}
}