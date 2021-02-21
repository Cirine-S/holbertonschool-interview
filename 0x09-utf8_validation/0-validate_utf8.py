#!/usr/bin/python3
"""
Method that validates an utf-8 data.
"""


def intList_to_binList(data):
    """Converts an integer list to a binary list."""
    bytes = []
    for n in data:
        num = '{:08b}'.format(n)
        bytes.append(num[-8:])
    return bytes


def validUTF8(data):
    """Check if a given data is a valid UTF-8 encoding."""
    binList = intList_to_binList(data)
    i = 0
    length = len(binList)

    while (i < length):
        if binList[i].startswith('0'):
            i += 1
        else:
            if binList[i].startswith('110'):
                tmp = binList[i + 1:i + 2]
                if (len(tmp) != 1):
                    return False
                if not (binList[i + 1].startswith('10')):
                    return False
                i += 2
            elif binList[i].startswith('1110'):
                tmp = binList[i + 1:i + 3]
                if (len(tmp) != 2):
                    return False
                if not (binList[i + 1].startswith('10') &
                        binList[i + 2].startswith('10')):
                    return False
                i += 3
            elif binList[i].startswith('11110'):
                tmp = binList[i + 1:i + 4]
                if (len(tmp) != 3):
                    return False
                if not (binList[i + 1].startswith('10') and
                        binList[i + 2].startswith('10') and
                        binList[i + 3].startswith('10')):
                    return False
                i += 4
            else:
                return False
    return True
