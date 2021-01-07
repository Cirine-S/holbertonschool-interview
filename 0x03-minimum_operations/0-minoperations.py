#!/usr/bin/python3
"""
Min Operations
"""


def minOperations(n):
    if (n <= 1):
        return 0
    sum = 0
    quotient = n
    for i in range(2, n+1):
        while (quotient % i == 0):
            quotient = quotient / i
            sum += i
    return sum
