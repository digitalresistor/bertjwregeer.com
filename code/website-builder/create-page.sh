#!/bin/bash

if [ ! 2 -eq $# ]; then
	echo "Please provide a path to the file you want to process, and the location to place the processed file!"
	exit
fi

FILENAME=`basename $1`
MYPATH=$1
OUTPUTPATH=$2
HEADER="./header.html"
FOOTER="./footer.html"

if [ ! -d $OUTPUTPATH ]; then
	/bin/mkdir $OUTPUTPATH
fi

OUTPUTNAME=`echo $FILENAME | sed -E "s/(.*)\.(.*)/\1/"`
OUTPUTFILENAME="${OUTPUTPATH}/${OUTPUTNAME}.html"

cat $HEADER > ${OUTPUTFILENAME}.tmp
./syntax-highlight ${MYPATH} >> ${OUTPUTFILENAME}.tmp
cat $FOOTER >> ${OUTPUTFILENAME}.tmp
sed -E "s/\{location\}/${OUTPUTNAME}/" ${OUTPUTFILENAME}.tmp > ${OUTPUTFILENAME}
rm ${OUTPUTFILENAME}.tmp
