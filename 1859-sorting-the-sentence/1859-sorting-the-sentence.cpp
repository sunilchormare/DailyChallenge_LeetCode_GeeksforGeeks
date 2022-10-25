class Solution {
public:
    string sortSentence(string s) {
       string word="" ;
        vector<string> v(10);
         for(int i=0;i<s.size();i++)  
         {
             if(s[i]>='0'&&s[i]<='9')
             {
                 v[s[i]-'0']=word +" ";
                 word="";
                 i++;
             }
           else
               word+=s[i];
         } 
       
      for(string x:v)
      {
          word+=x;
       
      }
         word.pop_back();

          return word;

    }
};