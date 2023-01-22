class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
       if(tomatoSlices < cheeseSlices * 2 || tomatoSlices > cheeseSlices * 4) return new ArrayList<>();
        
    int i = 0, j = cheeseSlices;
        
    while(i <= j){
        int mid = (i + j) / 2;
        int val = mid * 4 + (cheeseSlices - mid) * 2;
        if(val == tomatoSlices)
            return Arrays.asList(mid, cheeseSlices - mid);
        else if(val < tomatoSlices)
            i = mid + 1;
        else
            j = mid - 1;
    }
    return new ArrayList<>();
    }
}