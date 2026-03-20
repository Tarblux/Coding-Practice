#!/bin/bash


echo 'Setting up db with 256 for max_data and 100 rows'
./ex17_t2 test.db c 256 100

echo "Negative Tests"

set +e
./ex17_t2 test.db g 0
./ex17_t2 test.db d 0
./ex17_t2 test.db g 101
set -e

echo "Setting and getting alex and bob"

./ex17_t2 test.db s 0 alex 24 alex@jg.com
./ex17_t2 test.db g 0

./ex17_t2 test.db s 1 bob 39 bob@mail.com
./ex17_t2 test.db g 1

echo "deleting alex and bob"
./ex17_t2 test.db l
./ex17_t2 test.db d 0
./ex17_t2 test.db d 1

set +e
./ex17_t2 test.db g 0
./ex17_t2 test.db g 1
set -e