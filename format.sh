#!/usr/bin/env bash

find . -maxdepth 1 -name "*.c" -exec clang-format -style=LLVM -i {} +
find . -maxdepth 1 -name "*.h" -exec clang-format -style=LLVM -i {} +