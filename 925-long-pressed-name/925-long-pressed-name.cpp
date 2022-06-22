class Solution {
    public boolean isLongPressedName(String name, String typed) {
         int i=0,j=0;
        while(j<typed.length())
        {
            if(i<name.length()&&name.charAt(i)==typed.charAt(j))
                i++;
            else if(j==0 || typed.charAt(j)!=typed.charAt(j-1))
                return false;
              j++;  
        }
        return i==name.length();
    }
}