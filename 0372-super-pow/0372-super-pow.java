class Solution {
     public int superPow(int a, int[] b) {
      int res = 1;
      for(int i : b){
        res = pow(res, 10) * pow(a, i) % 1337;  
      }
      return res;
    }
    
    int pow(int x, int y){
        if(y == 0) return 1;
        if(y == 1) return x % 1337;
        return pow(x % 1337, y / 2) * pow(x % 1337, y - y / 2) % 1337;
    }
}