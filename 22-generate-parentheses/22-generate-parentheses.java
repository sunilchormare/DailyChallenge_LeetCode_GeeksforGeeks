    class Solution {
    public List<String> generateParenthesis(int n)
    {
    List<String> result=new ArrayList<>();
    helper(result,"",n,n);
    return result;
    }
    private void helper(List<String> result,String current,int left,int right)
    {
    if(left<0 || left>right) return;

    if(left==0 && right==0)
    {
    result.add(current);
    return;
    }
    helper(result,current+"(",left-1,right);
    helper(result,current+")",left,right-1);
    }
    }