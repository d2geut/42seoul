#!/bin/sh

cat /etc/passwd | grep -v '^#' | cut -d ':' -f 1 | rev | sort -r | tr '\n' ' ' | sed 's/ /, /g' | sed 's/, $/./'
