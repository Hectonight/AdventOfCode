#!/bin/bash

cd build || exit 1
make
./main < ../input.txt