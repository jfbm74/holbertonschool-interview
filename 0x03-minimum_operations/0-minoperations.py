#!/usr/bin/python3
"""
Minimum operations
"""


def minOperations(n):
    """
    Minimum operations
    """
    if type(n) is not int or n <= 1:
        return 0
    accu = []
    div = 2
    while (n % div) is 0 and (n // div) is not 1:
        accu.append(div)
        n = n // div
    div = 3
    while n > div:
        while (n % div) is 0 and (n // div) is not 1:
            accu.append(div)
            n = n // div
        div += 2
    accu.append(n)
    return sum(accu)
