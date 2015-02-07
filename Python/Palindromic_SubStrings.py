#!/bin/python


# Palindromic Substrings
# Zappos Interview Questions

import sys
import os

# Complete the function below.

def sub_string(input_string):
    length = len(input_string)
    sub_strings = set()
    for i in xrange(length):
        for j in xrange(i, length):
            sub_strings.add(input_string[i:j + 1])
    return sub_strings

def  palindrome(input_string):
    sub_string_set = sub_string(input_string)
    palindrome_set = set()

    for string in sub_string_set:
        if str(string) == str(string)[::-1]:
            palindrome_set.add(string)

    return len(palindrome_set)


# f = open(os.environ['OUTPUT_PATH'], 'w')


_str = raw_input()

res = palindrome(_str);
print(str(res))
# f.write(str(res) + "\n")

# f.close()
