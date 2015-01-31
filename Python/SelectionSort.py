# SelectionSort implementation in Python.
#
# Time Complexity of a Solution:
# Best:  O(n^2)
# Average: O(n^2)
# Worst: O(n^2)

import sys
import random
script, number = sys.argv


def SelectionSort(aList):
    for i in range(len(aList)):
        minimum = i
        for j in range(i + 1, len(aList)):
            if (aList[minimum] > aList[j]):
                minimum = j
        aList[minimum], aList[i] = aList[i], aList[minimum]
    print(aList)


def main():
    num = int(number)
    try:
        array = random.sample(xrange(100), num)
    except ValueError:
        print('Sample size exceeded population size.')
    print(array)
    SelectionSort(array)


main()
