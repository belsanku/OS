#!/bin/bash
#  
RED='\033[0;31m'
YELLOW='\033[0;33m'
REDBG='\033[37;1;41m'
NC='\033[0m' #
g++ lab3.11.cpp -o first.out -w
g++ lab3.12.cpp -o second.out -w
g++ lab3.13.cpp -o third.out -w
#
echo -e "${YELLOW}First part${NC}"
./first.out
echo;
echo -e "${YELLOW}Second part${NC}"
./second.out
echo;
echo -e "${YELLOW}Third part${NC}"
./third.out
#
cat test.dat
#
rm test.dat