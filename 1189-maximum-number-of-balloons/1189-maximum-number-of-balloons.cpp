class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // if(text.size()<7) return 0;
        // unordered_map<char,int> p;
        // for(char i:text)
        //     p[i]++;
        // int count=0;
        // for(int i=0;i<text.size();++i)
        // {
        //     if(p['b']==p['a']&&p['l']/2==p['o']/2&&p['b']==p['n'])
        //     {
        //         count++;
        //     }
        // }
        // return count;
        
        
          int b=0,a=0,l=0,o=0,n=0;
        for(int i=0;i<text.size();i++){
            switch (text[i]){
                case 'b':b++;
                    break;
                case 'a':a++;
                    break;
                case 'l':l++;
                    break;
                case 'o':o++;
                    break;
                case 'n':n++;
                    break;
            }
        }
        
        return min(b,min(a,min(l/2,min(o/2,n)))); 
    }
};