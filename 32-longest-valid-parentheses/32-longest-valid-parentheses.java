class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> st=new Stack<>();
        int result=0;
        st.push(-1);
        for(int i=0;i<s.length();++i)
        {
            if(s.charAt(i)=='(')
               st.push(i);
            else
            {
                st.pop();
                if(!st.empty())
                    result=Math.max(result,i-st.peek());
                else
                  st.push(i);
            }
                
            
        }
    return result;
    }
}