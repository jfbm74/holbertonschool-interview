#!/usr/bin/python3
""" This script solves the N queens problem. """
import sys

if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)
try:
    N = int(sys.argv[1])
except Exception:
    print('N must be a number')
    exit(1)

if N < 4:
    print('N must be at least 4')
    exit(1)

ans = []


def solve(i):
    """
    Recursive algorithm to solve the N queens problem.
    i is the current queen been placed (starting from 0)
    """
    for j in range(N):
        if ans == []:
            ans.append([i, j])
            solve(i + 1)
            ans.pop()
        else:
            test = [j == e[1] or abs(i - e[0]) == abs(j - e[1]) for e in ans]
            if not any(test):
                ans.append([i, j])
                if i == N - 1:
                    print(ans)
                else:
                    solve(i + 1)
                ans.pop()
