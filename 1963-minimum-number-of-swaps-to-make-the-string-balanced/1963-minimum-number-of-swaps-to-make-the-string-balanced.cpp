class Solution {
public:
    int minSwaps(string s) {
        int stack_size = 0;
        for (int i = 0; i < s.size (); i++) {
            char ch = s[i];
            if (ch == '[')
                stack_size++;
            else {
                if (stack_size > 0)
                    stack_size--;
            }
        }
        return (stack_size + 1) / 2;
        
    }
};