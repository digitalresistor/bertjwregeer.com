#!/bin/bash

if [ ! 1 -eq $# ]; then
	echo "Please provide a path to the file you want to process!"
	exit
fi

FILENAME=`basename $1`
MYPATH=$1
OUTPUTPATH="../../website"
HEADER="./header.html"
FOOTER="./footer.html"

if [ ! -d $OUTPUTPATH ]; then
	/bin/mkdir $OUTPUTPATH
fi

OUTPUTNAME=`echo $FILENAME | sed -E "s/(.*)\.(.*)/\1/"`
OUTPUTFILENAME="${OUTPUTPATH:=./temp}/${OUTPUTNAME}.html"

echo "Now creating ${OUTPUTFILENAME} using ${FILENAME} as input"

echo "Adding headers"

cat $HEADER > ${OUTPUTFILENAME}.tmp

echo "Syntax highlighting"

./syntax-highlight ${MYPATH} >> ${OUTPUTFILENAME}.tmp

echo "Adding footer"

cat $FOOTER >> ${OUTPUTFILENAME}.tmp

echo "Done creating file. Changing website title"

sed -E "s/\{location\}/${OUTPUTNAME}/" ${OUTPUTFILENAME}.tmp > ${OUTPUTFILENAME}

echo "Removing temporary files"

rm ${OUTPUTFILENAME}.tmp
