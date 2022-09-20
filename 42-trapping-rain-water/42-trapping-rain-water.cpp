class Solution {
public:
    int trap(vector<int>& A) {
          int left=0; int right=A.size()-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right])  {
                if(A[left]>=maxleft) 
                    maxleft=A[left],cout<<"maxleft : "<<maxleft<<endl;
                else
                    res+=maxleft-A[left],cout<<"res : "<<res<<endl;
               
                left++;
            }
            else{
                if(A[right]>=maxright)
                    maxright= A[right],cout<<"maxright : "<<maxright<<endl;
                else 
                    res+=maxright-A[right],cout<<"res : "<<res<<endl;
                
                right--;
            }
        }
        return res;
    }
};