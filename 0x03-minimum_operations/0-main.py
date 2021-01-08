#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 2
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 2147483640
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))