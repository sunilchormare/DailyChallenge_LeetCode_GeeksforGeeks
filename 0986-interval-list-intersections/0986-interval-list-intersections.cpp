class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
    //     List<int[]> res = new ArrayList();
    // for (int i = 0, j = 0; i < A.length && j < B.length; ) {
    //     int start = Math.max(A[i][0], B[j][0]);
    //     int end = Math.min(A[i][1], B[j][1]);
    //     if (start <= end)
    //         res.add(new int[]{start, end});
    //     if (A[i][1] < B[j][1])
    //         ++i;
    //     else
    //         ++j;
    // }
    // return res.toArray(new int[0][]);
       List<int[]> res=new ArrayList();
     //int tem=new int[2];
     int Aptr=0,Bptr=0;
    while(Aptr<A.length&&Bptr<B.length)
    {
        if(B[Bptr][0]<=A[Aptr][1]&&A[Aptr][0]<=B[Bptr][1])
        {
            int start=Math.max(A[Aptr][0],B[Bptr][0]);
            int end=Math.min(A[Aptr][1],B[Bptr][1]);
                res.add(new int[]{start,end});
        }
        if(A[Aptr][1]>B[Bptr][1])
           Bptr++;
        else
            Aptr++;
    }
    
        return res.toArray(new int[0][]);
    }
}