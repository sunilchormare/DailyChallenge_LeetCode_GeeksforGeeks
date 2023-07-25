class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        i=0
        while(A[i] < A[i+1]): 
            i+=1
        return i