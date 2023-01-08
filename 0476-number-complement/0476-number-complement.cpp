class Solution {
public:
    int findComplement(int num) {
       int i = 0;
        int j = 0;
        
        while (i < num)
        {
            i += pow(2, j);
            j++;
        }
        
        return i - num; 
    }
};