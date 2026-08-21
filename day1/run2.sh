#!/bin/bash

cd build || exit 1
make
./part2 < ../input.txt