class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] dc = new int[10];
        List<Integer> res = new ArrayList<Integer>();
        for(int d : digits){
            dc[d]++; // Counting number of occurrences of each digit
        }
		
		// Looping only 3 digit even numbers
        for(int i = 100; i < 999; i += 2){
            // Getting digits on place value 1's, 10's and 100's 
			int n = i;
            int b1 = n % 10;
            n = n / 10;
            int b10 = n % 10;
            n = n / 10;
            int b100 = n % 10;
			
            dc[b1]--;
            dc[b10]--;
            dc[b100]--;
			
            if(dc[b1] >= 0 && dc[b10] >= 0 && dc[b100] >= 0){
                res.add(i);
            }
			
            dc[b1]++;
            dc[b10]++;
            dc[b100]++;
        }
        return res.stream().mapToInt(i -> i).toArray();
    }
}