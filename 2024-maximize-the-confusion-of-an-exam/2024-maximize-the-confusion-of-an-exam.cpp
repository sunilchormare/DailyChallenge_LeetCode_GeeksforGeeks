class Solution {
public:
    int solve(string &s,char b,int &k){
       int left=0,res=0,size=s.size(),count=0;
      for(int i=0;i<size;i++)
      {
            if(s[i]==b)
                count++;
            if(count>k)
            {
                if(s[left]==b)
                    count--;
                left++;
            }
            
          res=max(i-left+1,res);
          //cout<<"res : "<<res<<endl;
        
      }
        return res;
    }
    
    int maxConsecutiveAnswers(string s, int k) {
       
         int f=solve(s,'F',k);
       // cout<<endl;
         int t=solve(s,'T',k);
        return max(f,t);  
    
    }
};