// class Solution {
//     private class LargerNumberComparator implements Comparator<String> {
//         @Override
//         public int compare(String a, String b) {
//             String order1 = a + b;
//             String order2 = b + a;
//            return order2.compareTo(order1);
//         }
//     }

//     public String largestNumber(int[] nums) {
//         // Get input integers as strings.
//         String[] asStrs = new String[nums.length];
//         for (int i = 0; i < nums.length; i++) {
//             asStrs[i] = String.valueOf(nums[i]);
//         }

//         // Sort strings according to custom comparator.
//         Arrays.sort(asStrs, new LargerNumberComparator());

//         // If, after being sorted, the largest number is `0`, the entire number
//         // is zero.
//         if (asStrs[0].equals("0")) {
//             return "0";
//         }

//         // Build largest number from sorted array.
//         String largestNumberStr = new String();
//         for (String numAsStr : asStrs) {
//             largestNumberStr += numAsStr;
//         }

//         return largestNumberStr;
//     }
// }

public class Solution {
     public String largestNumber(int[] num) {
		if(num == null || num.length == 0)
		    return "";
		
		// Convert int array to String array, so we can sort later on
		String[] s_num = new String[num.length];
		for(int i = 0; i < num.length; i++)
		    s_num[i] = String.valueOf(num[i]);
			
		// Comparator to decide which string should come first in concatenation
		Comparator<String> comp = new Comparator<String>(){
		    @Override
		    public int compare(String str1, String str2){
		        String s1 = str1 + str2;
				String s2 = str2 + str1;
				return s2.compareTo(s1); // reverse order here, so we can do append() later
		    }
	     };
		
		Arrays.sort(s_num, comp);
		// An extreme edge case by lc, say you have only a bunch of 0 in your int array
		if(s_num[0].charAt(0) == '0')
			return "0";
            
		StringBuilder sb = new StringBuilder();
		for(String s: s_num)
	        sb.append(s);
		
		return sb.toString();
		
	}
}