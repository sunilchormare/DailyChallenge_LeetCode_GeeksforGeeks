class Solution {
public:
    int countSeniors(vector<string>& details) {
        
      int count=0;
        for(string s:details){
            int age=((s[11]-'0')*10)+s[12]-'0';
            if(age>60) count++;
        }
        return count;
    }
};