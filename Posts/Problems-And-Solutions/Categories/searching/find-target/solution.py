class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        low, high = 10000, -1
        
        nums = sorted(nums)
        
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (right - left + 1) // 2 + left
            if target <= nums[mid]:
                if target == nums[mid]:
                    low = min(low, mid)
                right = mid - 1
            else:
                left = mid + 1
        
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (right - left + 1) // 2 + left
            if target >= nums[mid]:
                if target == nums[mid]:
                    high = max(high, mid)
                left = mid + 1
            else:
                right = mid - 1
        
        if low == 10000 or high == -1 or low > high:
            return []
        return [i for i in range(low, high + 1)]


sol = Solution()
print(sol.targetIndices([1,2,5,2,3], 2))
