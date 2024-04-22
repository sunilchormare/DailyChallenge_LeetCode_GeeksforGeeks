class Solution {
public:
    bool isThree(int n) {
        
        int count=2;
        if(n==2) return false;
        for(int i=2;i<n;++i)
        {
            if(n%i==0)
                count++;
            
        }
        if(count==3)
        {
            return true;
        }
        
        return false;
    }
};