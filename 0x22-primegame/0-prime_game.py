#!/usr/bin/python3
"""[Prime Game]
"""


def isWinner(x, nums):
    """[Prime Game]
    Args:
        x ([int]): [number of rounds]
        nums ([list]): [array of n]
    Returns:
        [string]: [name of the winner]
    """
    if not nums or x < 1:
        return None
    n = max(nums)
    arr = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not arr[i]:
            continue
        for j in range(i * i, n + 1, i):
            arr[j] = False
    arr[0] = arr[1] = False
    counter = 0
    for i in range(len(arr)):
        if arr[i]:
            counter += 1
        arr[i] = counter
    player = 0
    for n in nums:
        player += arr[n] % 2 == 1
    if player * 2 == len(nums):
        return None
    if player * 2 <= len(nums):
        return "Ben"
    return "Maria"
