def binary_search(array ,target) -> int:

    left, right = 0, len(array) - 1
    while left < right:
        mid = left + (right - left) // 2
        if mid == target :
            return mid
        elif mid < target:
            right = mid - 1 
        else:
            left = mid + 1
    return left