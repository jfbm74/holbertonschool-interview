#!/usr/bin/python3
"""
Module that determines if a given data set represents
a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    Function that determines if a given data set represents
    a valid UTF-8 encoding
    """
    try:
        bytes(number & 0xFF for number in data).decode()
        return True
    except UnicodeDecodeError:
        return False
