class Solution {
    public int eatenApples(int[] apples, int[] days) {
        PriorityQueue<int[]> appleStorage = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int appleCount = 0;
        
        for(int i = 0; i < apples.length || !appleStorage.isEmpty(); i++) {
            if(i < apples.length) {
                appleStorage.add(new int[]{ i + days[i], apples[i] });
            }
            
            while(!appleStorage.isEmpty() && (appleStorage.peek()[0] <= i || appleStorage.peek()[1] <= 0)) {
                appleStorage.poll();
            }
            
            if(!appleStorage.isEmpty()) {
                appleCount++;
                appleStorage.peek()[1]--;
            }
        }
        
        return appleCount;
    }
}