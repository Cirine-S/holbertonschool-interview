#!/usr/bin/python3
"""
Main file for testing
"""

isWinner = __import__('0-prime_game').isWinner

nums = [0] * 999
for i in range(999):
    nums[i] = i

print("Winner: {}".format(isWinner(999, nums)))
