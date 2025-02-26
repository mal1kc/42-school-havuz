#!/usr/bin/env bash

set -ex # stop on error amd output what will run
CC=clang

if [ $1 == "help" ]; then
  echo "add -c to create object file"
  echo "can add other flags for $(which $CC)"
  echo "- example usages -"
  echo "./compile_ex_wall.sh -c c_02/ex01/*.c -o libfile_01.o"
  echo "./compile_ex_wall.sh -c c_02/ex01/*.c -o libfile_01.o"
  echo "./compile_ex_wall.sh libfile_00.o libfile_01.o c_02/test_all.c"
  exit 0
fi
"$CC" -Wall -Wextra -Werror -g $*
