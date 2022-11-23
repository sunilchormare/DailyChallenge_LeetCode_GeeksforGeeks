class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        int map[] = new int[101], idx = 0, n = arr.length;

    for(int i = 0; i < pieces.length; i++)//store index of every part of pieces using first element as key
        map[pieces[i][0]] = i;

    while(idx < n){
        int j = map[arr[idx]];//get the index
        for(int e : pieces[j])//iterate the jth part of pieces
            if(e != arr[idx++])//if element in arr at index idx isn't equal to current element of pieces[j]
                return false;
    }
    return true;//we're here it means we can form the array arr
    }
}