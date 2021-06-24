#!/usr/bin/python3
"""
make change module
"""
import sys


def makeChange(coins, total):
    """[determine the fewest number of coins needed to meet a given amount total]

    Args:
        coins (list of integers): is a list of the values of the coins in your
        possession total (integer): total required amount

    Returns:
        [integer]: the fewest number of coins needed to meet that given amount
        total.
    """

    if (total <= 0):
        return 0
    n = len(coins)

    # Initialize Result
    ans = []

    # Sort Coins
    coins.sort()

    # Traverse through all denomination
    i = n - 1
    while(i >= 0):

        # Find denominations
        while (total >= coins[i]):
            total -= coins[i]
            ans.append(coins[i])

        i -= 1
    
    for i in range(len(ans)):
        print(ans[i], end = " ")

    if (total is not 0):
        return -1

    return len(ans)
