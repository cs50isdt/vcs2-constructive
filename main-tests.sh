#!/bin/bash

set -euo pipefail

die() {
  echo "Error: $1" >&2
  exit 1
}

expect_eq() {
  RESULT="$(./main "$2" "$3" "$4")"
  [ "$RESULT" = "$1" ] || die "Expected '$2 $3 $4' == $1 but got $RESULT"
}

expect_error() {
  ./main "$1" "$2" "$3" > /dev/null 2> /dev/null \
    && die "Expected '$1 $2 $3' to be an error but it wasn't" \
    || true
}

expect_eq 3 1 + 2
expect_eq -1 3 - 4
expect_eq 10 2 '*' 5
expect_eq 20 100 / 5

expect_error 1 + qwerty
expect_error qwerty + 2
