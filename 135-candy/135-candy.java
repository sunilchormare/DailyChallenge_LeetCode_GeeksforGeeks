class Solution {
public:
    int candy(vector<int>& ratings) {
//       int n=ratings.size();
//         vector<int> left(n);
//         vector<int> right(n);
//          for(int i=0;i<n;++i) left[i]=1;
//          for(int i=0;i<n;++i) right[i]=1;
        
//         for(int i=1;i<n;++i)
//         {
//           if(ratings[i]>ratings[i-1])
//               left[i]=left[i-1]+1;
              
//         }
//           for(int i=n-1;i>=0;--i)
//         {
//           if(ratings[i-1]>ratings[i])
//               right[i-1]=right[i]+1;
              
//         }
//         int res=0;
//         for(int i=0;i<n;++i)
//             res+=max(left[i],right[i]);
        
//         return res;        
        
        int size=ratings.size();
	 if(size<=1)
		 return size;
	 vector<int> num(size,1);
	 for (int i = 1; i < size; i++)
		 if(ratings[i]>ratings[i-1])
			 num[i]=num[i-1]+1;
	 
	 for (int i= size-1; i>0 ; i--)
		 if(ratings[i-1]>ratings[i])
			 num[i-1]=max(num[i]+1,num[i-1]);
	 
	 int result=0;
	 for (int i = 0; i < size; i++)
		 result+=num[i];
		// cout<<num[i]<<" ";
	 return result;
        
    }
};