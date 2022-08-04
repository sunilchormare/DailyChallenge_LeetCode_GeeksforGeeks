class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        while(q%2==0 and p%2==0):
            p/=2;
            q/=2;
        if(q%2==0 and p%2!=0): return 0;
        if(q%2!=0 and p%2==0): return 2;
        if(q%2!=0 and p%2!=0): return 1;
        return -1;
        