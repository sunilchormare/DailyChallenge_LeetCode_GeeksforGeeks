class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int c=0;
        for(int i=1;i<arr.length-1;++i)
        {
            if(arr[i]%2!=0&&arr[i-1]%2!=0&&arr[i+1]%2!=0)
            {
                c+=3;
            }
           
                
            
        }
        // if(c>=3) return true;
        // else return false;
        
        return (c>=3)?true:false;
    }
}