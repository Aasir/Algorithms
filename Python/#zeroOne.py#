# Zappos Interview Question

def zeroOne(input_value):
    for i in xrange(1, 100000):
        current_number = i*input_value
        number_set = set(str(current_number))
        if (len(number_set) == 2):
            if ("1" in number_set) and ("0" in number_set):
                return int(current_number)

n = int(raw_input())

print(zeroOne(n))
