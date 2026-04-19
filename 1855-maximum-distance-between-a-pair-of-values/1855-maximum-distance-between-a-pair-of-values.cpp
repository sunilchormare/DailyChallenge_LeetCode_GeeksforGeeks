class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
 //        int m=nums1.size(),n=nums2.size();
 //        int maxD=0;
 //        for(int i=0;i<m;++i)
 //            for(int j=0;j<n;++j)
 //                if(i<=j&&nums1[i]<=nums2[j])
 //                   maxD=max(maxD,j-i);       
 // return maxD;        
     
        int i = 0, j = 0, res = 0, n = A.size(), m = B.size();
        while (i < n && j < m) {
            if (A[i] > B[j])
                i++;
            else
                res = max(res, j++ - i);
        }
        return res;
    }
};