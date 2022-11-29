class Solution {
    public int secondHighest(String s) {
       char first = '0' - 10, second = first;
    for(char c : s.toCharArray()){
        if(Character.isDigit(c)){
            if(c > first){
                second = first;
                first = c;
            } else if(c != first && c > second)
                second = c;
        }
    }
    return second >= '0' ? second - '0' : -1; 
    }
}