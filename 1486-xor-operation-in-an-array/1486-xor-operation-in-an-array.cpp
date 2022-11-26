class Solution {
public:
    int xorOperation(int n, int start) {
        int xors=0;
        int nums[n];
        for(int i=0;i<n;++i)
        {
            nums[i]=start+2*i;
            xors^=nums[i];
        }
        return xors;
    }
};