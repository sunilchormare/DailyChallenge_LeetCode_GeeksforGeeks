class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
            result = 0
            cnt = [0] * 101

            for num in nums:
                cnt[num] = cnt[num] + 1

            for i in range(k+1, 101):
                result += cnt[i] * cnt[i - k]

            return result