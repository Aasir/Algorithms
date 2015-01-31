# InsertionSort implementation in Python.
#
# Time Complexity of a Solution:
# Best:  O(n)
# Average: O(n^2)
# Worst: O(n^2)
#
# InsertionSort is a good algorithms for small datasets.

import sys
import random
script, number = sys.argv


def InsertionSort(aList):
    for i in range(1, len(aList)):
        element = aList[i]
        j = i
        while (j > 0 and aList[j - 1] > element):
            aList[j] = aList[j - 1]
            j = j - 1
        aList[j] = element
    print(aList)


def main():
    num = int(number)
    try:
        array = random.sample(xrange(100), num)
    except ValueError:
        print('Sample size exceeded population size.')
    print(array)
    InsertionSort(array)


main()
