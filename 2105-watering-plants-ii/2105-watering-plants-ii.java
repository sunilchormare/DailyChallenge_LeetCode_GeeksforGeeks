class Solution {
    public int minimumRefill(int[] plants, int capacityA, int capacityB)
    { int ptA=0, ptB=plants.length-1, canA=capacityA, canB=capacityB, res=0;
        while(ptA<ptB) {
            if(canA<plants[ptA]) {
                res++;
                canA=capacityA;
            }
            if(canB<plants[ptB]) {
                res++;
                canB=capacityB;
            }
            canA-=plants[ptA++];
            canB-=plants[ptB--];
        }
        if(ptA==ptB&&canA<plants[ptA]&&canB<plants[ptB]) res++;
        return res;
    }
}