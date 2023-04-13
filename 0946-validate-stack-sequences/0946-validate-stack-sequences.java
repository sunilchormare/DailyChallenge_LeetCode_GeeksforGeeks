class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//          stack<int> stack;
//         int i = 0;
//         for (int x : pushed) {
//             stack.push(x);
            
//             while (stack.size() && stack.top() == popped[i]) {
//                 stack.pop();
//                 i++;
//             }
//         }
//         return stack.size() == 0;
        
        
        int i = 0, j = 0;
        for (int x : pushed) {
            pushed[i++] = x;
           // cout<<" i= "<<i<<" pushed["<<i<<"] = "<<pushed[i]<<endl;
            while (i > 0 && pushed[i - 1] == popped[j])
            {
                --i, ++j;
                //cout<<" i= "<<i<<" pushed["<<i<<"] = "<<pushed[i]<<endl;
            }
            //cout<<endl;
        }
        return i == 0;
    }
};