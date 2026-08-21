#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <day> [part]"
    echo "Example: $0 1 2"
    exit 1
fi

DAY=$1
PART=${2:-1}

cmake --build build --target run_day"${DAY}"_part"${PART}"
