# Requires the array to be sorted
# Time Complexity:
# Best = Average = O(logn)
# Worst = O(1)


# Binary Search Implemented as an Iterative Function
def BinarySearchIterative(arr, value):
    low, high = 0, len(arr) - 1
    while (low <= high):
        mid = (low + high) / 2
        if arr[mid] == value:
            return mid
        elif arr[mid] < value:
            low = mid + 1
        else:
            high = mid - 1
    return -1


# Binary Search Implemented as a Recursive Function
def BinarySearch(arr, value, low, high):
    if high < low:
        return -1
    else:
        mid = (low + high) / 2
        if arr[mid] < value:
            return BinarySearch(arr, value, mid + 1, high)
        elif arr[mid] > value:
            return BinarySearch(arr, value, low, mid - 1)
        else:
            return mid
