#!/usr/bin/python3
"""Write a script that reads stdin line by line and computes metrics"""

import sys

acum = 0
codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
status = {}

try:
    for i, line in enumerate(sys.stdin, 1):
        split = line.split(' ')
        if len(split) < 2:
            continue
        code = split[-2]
        size = split[-1]
        if code not in status and code in codes:
            status[code] = 1
        elif code in status and code in codes:
            status[code] = status[code] + 1
        acum = acum + eval(size)
        if i % 10 == 0:
            print("File size: {}".format(acum))
            for key in sorted(status.keys()):
                print("{}: {}".format(key, status[key]))
finally:
    print("File size: {}".format(acum))
    for key in sorted(status.keys()):
        print("{}: {}".format(key, status[key]))
