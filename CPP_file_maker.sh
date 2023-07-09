#!/usr/bin/env bash

BLACK="\033[0;30m"
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
PURPLE="\033[0;35m"
CYAN="\033[0;36m"
WHITE="\033[0;37m"
makefile_path=$(readlink -f ./Makefile)

echo "Welcome $USER to the lazy CPP file maker"

while :; do
	echo -e -n "${GREEN}Please enter how many folders you want to create ${WHITE}"
    read -ep '>' number
    [[ $number =~ ^[[:digit:]]+$ ]] || { echo "Please enter a digit"; continue; }
    (( ( (number=(10#$number)) <= 9 ) && number >= 1 )) || { echo "Number out of 1-9 scope"; continue;}
    break
done

for ((i = 0 ; i < $number ; i++)); do
	mkdir ex0$i
	cd ex0$i
	file_list=()
	read -p "Enter the file names for ex0$i (separated by spaces): " -a filenames
	touch "${filenames[@]/%/.c}"
  touch "${filenames[@]/%/.hpp}"
	touch main.cpp
	cp $makefile_path .
	read -p "Enter the executable name: " new_executable_name
	sed -i "s/NAME = #executable/NAME = $new_executable_name/g" Makefile
	read -p "Enter the source file names for ex0$i (separated by spaces): " -a src_files
	# src=$(printf "%s\n" "${src_files[@]/%/.cpp}")
	# sed -i "s/#src/$src/g" Makefile
	cd ..
done
