# QuickSort implementation in Python.
#
# Time Complexity of a Solution:
# Best:  O(n*logn)
# Average: O(n*logn)
# Worst: O(n^2)

import sys
import random
script, number = sys.argv


def QuickSort(aList, left, right):
    if left < right:
        # Partiting the list
        p = Partition(aList, left, right)

        # Recursive Calls
        QuickSort(aList, left, p - 1)
        QuickSort(aList, p + 1, right)
    return aList


def Partition(aList, left, right):
    # Initial Values
    i, j, pivot_value = left - 1, right, aList[right]
    while i < j:
        i = i + 1
        while (i <= right and aList[i] < pivot_value):
            i = i + 1
        j = j - 1
        while (j >= left and aList[j] > pivot_value):
            j = j - 1
        if i <= right:
            aList[i], aList[j] = aList[j], aList[i]
    if i <= right:
        aList[i], aList[j] = aList[j], aList[i]
    aList[i], aList[right] = aList[right], aList[i]
    return i


def main():
    num = int(number)
    try:
        array = random.sample(xrange(100), num)
    except ValueError:
        print('Sample size exceeded population size.')

    print(array, array[0], array[len(array) - 1])
    sortedArray = QuickSort(array, 0, len(array) - 1)
    print(sortedArray)


main()
