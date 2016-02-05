#!/bin/bash

LD_PRELOAD="/home/barthe_g/rendu/tek2/unix_Reseau/PSU_2015_malloc/libmy_malloc.so" ./a.out

valgrind --trace-children=yes ./test_ls.sh
