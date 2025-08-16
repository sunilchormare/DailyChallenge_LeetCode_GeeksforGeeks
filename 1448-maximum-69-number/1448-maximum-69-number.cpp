class Solution {
public:
    int maximum69Number (int num) {
//         string n=to_string(num);
//         int maxi=0,count=0;
//         for(int i=0;i<n.size();++i)
//         {
//             char c=n[i];
//             if(n[i]=='6') 
//             {
//                 n[i]='9';
//                 int temp=stoi(n);
//                 maxi=max(maxi,temp);
//                 n[i]=c;
//             }
//             else count++;
            
            
//         }
//         return count==n.size()?num:maxi;
        
         string s_num = to_string(num);
        for (auto &c : s_num) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(s_num);
    }
};