class Solution 
{
public:
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
      vector<vector<int>> res;
     vector<int> tem(2);
     int Aptr=0,Bptr=0;
    while(Aptr<A.size()&&Bptr<B.size())
    {
        if(B[Bptr][0]<=A[Aptr][1]&&A[Aptr][0]<=B[Bptr][1])
        {
            tem[0]=max(A[Aptr][0],B[Bptr][0]);
            tem[1]=min(A[Aptr][1],B[Bptr][1]);
                res.push_back(tem);
        }
        if(A[Aptr][1]>B[Bptr][1])
          Bptr++;
        else
            Aptr++;
    }
    
        return res;
}
};