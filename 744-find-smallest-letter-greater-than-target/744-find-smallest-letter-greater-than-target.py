class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        n = len(letters)
        if(target >= letters[n - 1]):
            return letters[0]
        
        left = 0
        right = n - 1
        while(left < right):
                mid = left + (right - left)//2
                if(letters[mid] <= target):
                    left = mid + 1
                else:
                    right = mid
        return letters[right]