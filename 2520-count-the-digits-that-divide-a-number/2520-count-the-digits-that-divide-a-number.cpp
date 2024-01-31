class Solution {
public:
    int countDigits(int x) {
        
//         int count=0;
//         set<int> s;
//         while(num>0)
//         {
//             int val=num%10;
            
//             if(num%val==0&&s.count(val)!=1)
//             {
//                 count++;
//                 s.insert(val);
//             }
//             num/=10;
//         }
//         return count;
        
        int res = 0;
        for (auto& c: to_string(x))
            if (x % (c - '0') == 0)
                res++;
        return res;
    }
};