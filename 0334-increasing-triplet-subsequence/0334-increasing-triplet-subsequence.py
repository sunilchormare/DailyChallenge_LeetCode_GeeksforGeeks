
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        small,big=10000000000,10000000000
        for n in nums:
            if n <= small: 
                small = n
            elif n <= big:
                big = n 
            else:
                return True
        return False