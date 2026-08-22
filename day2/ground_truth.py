import re
import os

# This file is slow, its only purpose is to check for
# correctness of the solution. NOT for performance.

os.chdir(os.path.dirname(__file__))

regex = re.compile(r"^(\d+)\1+$")

f = open("input.txt", "r")
x = f.read().strip()
f.close()
x = x.split(",")
sp = [r.split("-") for r in x]
p = [tuple(map(int, pair)) for pair in sp]

s = 0
for lower, upper in p:
    for i in range(lower, upper + 1):
        if regex.match(str(i)):
            s += i

print(s)
