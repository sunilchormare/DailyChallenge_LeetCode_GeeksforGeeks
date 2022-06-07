class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
//         for(int i=0;i<image.size();++i)
//         {
//             int p=0,q=image.size()-1;
//             while(p<q)
//                 image[i][p]=image[i][q];
            
//         }
        
//          return image;
    
        
       for (auto& row : A) {
            reverse(row.begin(), row.end());
            for (auto& v : row) v ^= 1;
        }
        return A;
        
    }
};