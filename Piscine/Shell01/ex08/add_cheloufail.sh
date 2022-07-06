#!/bin/sh

num1=$FT_NBR1
num2=$FT_NBR2

result1=$(echo "${num1}" | tr "'" "0" | tr '\' '1' | tr '"' '2' | tr '?' '3' | tr '!' '4')
RESULT1=$(echo "${num2}" | tr "m" "0" | tr 'r' '1' | tr 'd' '2' | tr 'o' '3' | tr 'c' '4')

result2=$(echo "ibase=5; ${result1}" | bc)
RESULT2=$(echo "ibase=5; ${RESULT1}" | bc)

RESULT3=$(echo "${result2} + ${RESULT2}" | bc)

RESULT4=$(echo "obase=13; ${RESULT3}" | bc)

RESULT5=$(echo "${RESULT4}" | tr '0123456789ABC' 'gtaio luSnemf')

echo ${RESULT5}
