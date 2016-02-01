#!/bin/bash

LD_PRELOAD="/home/dupard_e/rendus/PSU_2015_malloc/libmy_malloc.so" ls

valgrind --trace-children=yes ./test_ls.sh
