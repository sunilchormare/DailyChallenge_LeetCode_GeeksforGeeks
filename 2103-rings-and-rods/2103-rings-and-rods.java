class Solution {
    public int countPoints(String rings) {
        int[] rods = new int[10];
        for(int i = 0; i < rings.length() - 1; i += 2){
            if(rings.charAt(i) == 'R')
                rods[rings.charAt(i + 1) - '0'] |= (1 << 0);
            if(rings.charAt(i) == 'G')
                rods[rings.charAt(i + 1) - '0'] |= (1 << 1);
            if(rings.charAt(i) == 'B')
                rods[rings.charAt(i + 1) - '0'] |= (1 << 2);
        }
        int total = 0;
        for(int i = 0; i < rods.length; i++){
            if(rods[i] == 7)
                total++;
        }
        return total;
    }
}