# Zappos Interview Question

import math

def superPower(input_string):
    number = input_string

    for i in xrange(1, number):
        for j in xrange(1, number):
            if (math.pow(i,j) == number):
                return 1

    return 0
tp

print(superPower(9))
