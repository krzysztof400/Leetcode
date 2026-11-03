class Solution:
    def minMoves(self, nums: List[int]) -> int:
        maxel = max(nums)
        result = 0 
        for i in range(len(nums)):
            result = result + (maxel - nums[i])
        return result
