#!/bin/bash

if [ ! 2 -eq $# ]; then
	echo "$1 <path to code> <path to output>"
	exit
fi

if [ ! -d $2 ]; then
	echo "Output directory does not exist, creating ..."
	mkdir $2
fi

for I in `find $1 -type d | grep -v ".svn"`; do
	echo ${I#$1};
	
	if [ ! -d $2/${I#$1} ]; then
		echo "Creating directory $2${I#$1}"
		mkdir $2/${I#$1}
	fi
	
	for J in `find $I -type f -depth 1 | grep -v ".svn" | grep -v ".DS_Store" | grep -v "Makefile"`; do
		echo -e "\t ${J#$1}"
		./create-page.sh ${J} $2/${I#$1}
	done
done