class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), m = A[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n-1; j++){
                if(A[j][i] > A[j+1][i]){
                    count++;
                    break;
                }
                    
            }
            
        }
        return count;
    }
};