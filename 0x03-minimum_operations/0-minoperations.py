#!/usr/bin/python3
"""
Min Operations
"""


def minOperations(n):
    if (n <= 1):
        return 0
    sum = 0
    i = 2
    while i <= n:
        while (n % i == 0):
            n = n / i
            sum += i
        i += 1
    return sum
