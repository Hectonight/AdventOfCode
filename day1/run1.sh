#!/bin/bash

cd build || exit 1
make
./part1 < ../input.txt