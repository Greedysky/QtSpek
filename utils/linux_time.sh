#!/bin/sh

find . -exec touch -c -m -d "2023-01-11 00:00" {} \;
