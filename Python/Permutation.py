def permute(s):

# Returns a set of the permutations of the given string

# Algorithm:
# 1. Define a substring which is the string to permute minus the last letter
# 2. Get the permutations of the substring (recursion)
#     2.1 A substring of length 1 has only one permutation (itself)
# 3. For each permutation from step 2 (called a 'seed')
#     3.1 Add the final character of the string to each potential location
#     in the seed (ie at the beginning, between each letter, and at
#     the end) in turn
#     3.2 These are the permutations of the string

# To understand this algorithm try doing it on paper:
# Permute "A" --> A
# Then permute "AB" --> AB, BA
# Then permute "ABC" --> CAB, ACB, ABC, CBA, BCA, BAC

# Realise that what your doing each time you lengthen the string by a
# character is you're adding the new character to each potential location
# in the permutations of the previous string - this is most obvious in the
# "ABC" example:
#     Add C to each point in AB --> CAB, ACB, ABC
#     Add C to each point in BA --> CBA, BCA, BAC


    if len(s) == 1:
        return set([s])

    perms = set()

    for seed in permute(s[:-1]):
        for position in range(len(s)):
            perms.add(seed[:position] + s[-1] + seed[position:])

    return perms


print(permute("aba"))
