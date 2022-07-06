#!/bin/sh

ifconfig | sed -n '/ether /p' | cut -d ' ' -f2
