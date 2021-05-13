#!/usr/bin/python3
"""Minimum operations"""


def minOperations(n):
    """Minimum operations"""
    if type(n) is not int or n <= 1:
        return 0
    num_h = 1
    cp = 1
    op = 1
    while num_h < n:
        if n % num_h == 0 and num_h != cp:
            copy = num_h
            op += 1
        num_h = num_h + cp
        op += 1
    if num_h == n:
        return op
    return 0
