#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

if [ -z "$1" ]; then
    echo "Usage: $0 <day> [part] [extra]"
    echo "Examples:"
    echo "  $0 1       # Runs run_day1_part1"
    echo "  $0 1 2     # Runs run_day1_part2"
    echo "  $0 1 1 old # Runs run_day1_part1_old"
    exit 1
fi

DAY=$1
PART=${2:-1}
EXTRA=${3:+_$3}

cmake --build build --target run_day"${DAY}"_part"${PART}""${EXTRA}"
