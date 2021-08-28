#!/usr/bin/python3
"""[Prime Game]
"""


def isprime(j):
    """[checks if a number is a prime one]

    Args:
        j ([int]): [number to check]

    Returns:
        [boolean]: [true if prime, else false]
    """
    for i in range(2, j):
        if j % i == 0:
            return False
    return True


def isWinner(x, nums):
    """[Prime Game]

    Args:
        x ([int]): [number of rounds]
        nums ([list]): [array of n]

    Returns:
        [string]: [name of the winner]
    """
    ben = 0
    maria = 0
    if x <= 0:
        return None
    for n in nums:
        if n == 1:
            ben += 1
        else:
            count = 0
            for i in range(2, n + 1):
                if isprime(i):
                    count += 1
            if (count % 2 == 0):
                ben += 1
            else:
                maria += 1
    if (ben > maria):
        return "Ben"
    elif (ben < maria):
        return "Maria"
    else:
        return None
