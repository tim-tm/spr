#!/usr/bin/env bash

set -xe

gcc -Wall -Wextra -pedantic -ggdb2 main.c -o dh -lm
