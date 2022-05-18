#!/bin/sh

cat /etc/passwd | grep -v '^#' | sed -n 'n;p' | cut -d ':' -f 1 | rev | sort -r | awk -v start=$FT_LINE1 -v end=$FT_LINE2 ' NR >= start && NR <= end {print} ' | tr '\n' ' ' | sed 's/ /, /g' | sed 's/, $/./'
