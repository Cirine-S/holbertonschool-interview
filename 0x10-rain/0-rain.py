#!/usr/bin/python3
"""
rain func
"""


def rain(walls):
    if walls == [] or len(walls) == 0:
        return 0
    water = 0
    n = len(walls)

    result = 0
    left_max = 0
    right_max = 0

    # indices to traverse the array
    low = 0
    high = n-1

    while(low <= high):

        if(walls[low] < walls[high]):

            if(walls[low] > left_max):

                # update max in left
                left_max = walls[low]
            else:

                # water on curr element = max - curr
                result += left_max - walls[low]
            low += 1

        else:

            if(walls[high] > right_max):
                # update right maximum
                right_max = walls[high]
            else:
                result += right_max - walls[high]
            high -= 1

    return result
