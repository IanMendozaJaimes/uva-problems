def search(nums, target) -> int:
    left = 0
    right = len(nums) - 1
    
    while left <= right:
        middle = left + int((right - left) / 2)
        print(middle)
        if nums[middle] == target:
            return middle
        
        if nums[middle] >= nums[left]:
            print('path 1')
            if nums[middle] > target and nums[left] <= target:
                right = middle - 1
            else:
                left = middle + 1
        else:
            print('path 2')
            if nums[middle] > target and nums[right] >= target:
                left = middle + 1
            else:
                right = middle - 1
    
    return -1

search([1,3], 3)
