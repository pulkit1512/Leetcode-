class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        maxi=len(nums)
        sum1=0
        for i in range(len(nums)):
            sum1+=nums[i]
           
        return maxi*(maxi+1)//2 - sum1