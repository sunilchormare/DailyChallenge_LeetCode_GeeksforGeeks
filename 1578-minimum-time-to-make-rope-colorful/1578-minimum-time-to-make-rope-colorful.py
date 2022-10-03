class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        cost=0
        curMax=0
        for i in range(len(colors)):
            if(i>0 and colors[i]!=colors[i-1]):
                curMax=0
            cost+=min(curMax,neededTime[i])
            curMax=max(curMax,neededTime[i])
        return cost