class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        start=0
        end=len(nums)-1
        
        while start<=end:
            mid=start+(end-start)//2
            if mid == 0:
                leftval = -10000000000
            else:
                leftval = nums[mid - 1]
            if mid==len(nums)-1:
                rightval =  -100000000000
            else :
                rightval = nums[mid+1]
            if nums[mid]>=rightval and nums[mid]>=leftval:
                return mid
            elif nums[mid]<rightval:
                start=mid+1
            else:
                end=mid-1                  
        return -1
            