class Solution:
    def threeSum(nums):
            
        result = []

        nums.sort()

        for i in range (0,len(nums)) : 

            if i > 0 and nums[i] == nums[i-1] : 

                continue

            right = len(nums) - 1

            left = i + 1

            while left < right : 

                cur_sum = nums[i] + nums[left] + nums[right]

                if cur_sum == 0 :

                    result.append([nums[i],nums[left],nums[right]])

                    # left += 1
                    # right -= 1
                    
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                if cur_sum < 0 :

                    left += 1

                if cur_sum > 0 :

                    right -= 1
                    
        return result
    
print (Solution.threeSum([-1,0,1,2,-1,-4]))
    
