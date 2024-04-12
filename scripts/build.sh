#!/usr/bin/env bash

set -eux

mkdir -p build

cmake -S `pwd` -B build
cmake --build build --target nvcuvid-stub
