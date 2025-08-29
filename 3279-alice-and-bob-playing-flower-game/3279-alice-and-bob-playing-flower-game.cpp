class Solution {
public:
    long long flowerGame(int n, int m) {
         long long oddx=0, eveny=0, evenx=0, oddy=0;
        
        evenx = n/2;
        oddx = n%2 == 0 ? evenx : evenx+1;
        eveny = m/2;
        oddy = m%2 == 0 ? eveny : eveny+1;
        
        return oddx*eveny + evenx*oddy;
    }
};