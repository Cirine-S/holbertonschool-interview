#!/usr/bin/python3
"""
Pascal triangle function
"""
def pascal_triangle(n):
    """
    Returns a list of lists of ints representing the Pascal’s triangle of n
    """
    matrix = []
    if n <= 0:
        return matrix
    matrix = [[1]]
    for i in range(1, n):
        tmp = [1]
        for j in range(len(matrix[i - 1]) - 1):
            current = matrix[i - 1]
            tmp.append(matrix[i - 1][j] + matrix[i - 1][j + 1])
        tmp.append(1)
        matrix.append(tmp)
    return matrix
