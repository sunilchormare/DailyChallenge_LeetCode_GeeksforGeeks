class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def helper(current,left,right,res):
            if(left<0 or left>right): return;
            if(left==0 and right==0):
                res.append(current)
                return
            helper(current+"(",left-1,right,res)
            helper(current+")",left,right-1,res)
        res=[]
        helper("",n,n,res)
        return res