# MergeSort implementation in Python.
#
# Time Complexity of a Solution:
# Best = Average = Worst = O(nlogn)


import sys
import random
script, number = sys.argv


def MergeSort(aList):
    length = len(aList)
    # Return if we only have one element
    if length < 2:
        return aList

    # Sort the two halves of the list.
    mid = length / 2
    left = aList[:mid]
    right = aList[mid:]
    # print("Left: ", left, type(left))
    # print("Right: ", right, type(right))

    # Recursively call the sort functions
    left = MergeSort(left)
    right = MergeSort(right)

    # Merge them together
    sortedList = Merge(left, right)
    return sortedList


def Merge(left, right):
    sortedList = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sortedList.append(left[i])
            i = i + 1
        else:
            sortedList.append(right[j])
            j = j + 1
    while i < len(left):
        sortedList.append(left[i])
        i = i + 1
    while j < len(right):
        sortedList.append(right[j])
        j = j + 1

    # print("Sorted List Type:", sortedList, type(sortedList))
    return sortedList


def main():
    num = int(number)
    try:
        array = random.sample(xrange(100), num)
    except ValueError:
        print('Sample size exceeded population size.')
    print(array)
    sortedList = MergeSort(array)
    print(sortedList)


main()
