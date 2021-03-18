#!/usr/bin/python3
'''A python program that solves the N queens problem'''
from sys import argv


if (len(argv) != 2):
    print('Usage: nqueens N')
    exit(1)
elif not argv[1].isdigit():
    print('N must be a number')
    exit(1)
elif int(argv[1]) < 4:
    print('N must be at least 4')
    exit(1)
