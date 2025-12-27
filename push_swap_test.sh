#!/bin/bash

PS=./push_swap
CHK=./checker_linux

echo "=============================="
echo " PUSH_SWAP FULL TEST SCRIPT"
echo "=============================="
echo

#######################################
# 1. BOŞ / WHITESPACE TESTLERİ
#######################################
echo "[1] Empty / Whitespace tests"

$PS "" | cat -e
$PS " " | cat -e
$PS "   " | cat -e
$PS "	" | cat -e

echo

#######################################
# 2. GEÇERSİZ TOKEN TESTLERİ
#######################################
echo "[2] Invalid token tests"

tests_invalid=(
"a"
"1 a 2"
"1 2b 3"
"a b c d"
"42 ok 100"
)

for t in "${tests_invalid[@]}"; do
	echo "Test: \"$t\""
	$PS "$t"
	echo
done

#######################################
# 3. SIGN (+ / -) HATALARI
#######################################
echo "[3] Sign error tests"

tests_sign=(
"+"
"-"
"++"
"--"
"+-1"
"-+1"
"1 + 2"
"1 ++2 3"
"1 --2 3"
"1 2- 3"
"1 -+2 3"
)

for t in "${tests_sign[@]}"; do
	echo "Test: \"$t\""
	$PS "$t"
	echo
done

#######################################
# 4. DUPLICATE TESTLERİ
#######################################
echo "[4] Duplicate tests"

tests_dup=(
"1 1"
"0 1 2 3 2"
"4 4 4"
"10 20 30 10"
)

for t in "${tests_dup[@]}"; do
	echo "Test: \"$t\""
	$PS "$t"
	echo
done

#######################################
# 5. INT OVERFLOW / UNDERFLOW
#######################################
echo "[5] Overflow / Underflow tests"

tests_overflow=(
"2147483648"
"-2147483649"
"99999999999999999999"
"-99999999999999999999"
)

for t in "${tests_overflow[@]}"; do
	echo "Test: \"$t\""
	$PS "$t"
	echo
done

#######################################
# 6. ZATEN SIRALI
#######################################
echo "[6] Already sorted"

$PS "0 1 2 3 4" | wc -l
echo

#######################################
# 7. 3 ELEMAN TESTLERİ
#######################################
echo "[7] 3 elements (max 3 moves)"

for t in "2 1 3" "3 2 1" "2 3 1"; do
	echo "Test: $t"
	$PS $t | wc -l
done

echo

#######################################
# 8. 5 ELEMAN TESTLERİ
#######################################
echo "[8] 5 elements (max 12 moves)"

tests_5=(
"5 4 3 2 1"
"1 5 2 4 3"
"2 1 3 5 4"
)

for t in "${tests_5[@]}"; do
	echo "Test: $t"
	$PS $t | wc -l
done

echo

#######################################
# 9. CHECKER DOĞRULAMA
#######################################
echo "[9] Checker tests"

ARG="3 2 5 1 4"
$PS $ARG | $CHK $ARG

echo

#######################################
# 10. RANDOM 100
#######################################
echo "[10] Random 100"

ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
$PS $ARG | $CHK $ARG

echo
echo "=============================="
echo " TESTS FINISHED"
echo "=============================="
