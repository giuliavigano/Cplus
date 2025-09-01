#!/bin/bash

REPLACED_BIN="./replaced"
TEST_DIR="./replaced_tests"
GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

generate_file() {
	if [ ! -d "$TEST_DIR" ]; then
		mkdir $TEST_DIR
	fi;
	echo "aaa" > $TEST_DIR/onematch
	echo "ccasdsappddas" > $TEST_DIR/one_arg
	echo "jkajkasksk mi" > $TEST_DIR/two_args
	echo "cioa mi chiamo mi giulia aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa mimi sento stanca e mi non so piu mi cosa mi scrivere su questa mi riga mi sa che sto mi un po mi esagerando ma mi e un smi test mi lungo, mi sto mi annoiando" > $TEST_DIR/linelong
	{
		echo "niao mi mento ciao"
		echo "mi nato sono mi io"
		echo "miao micio sono mi"
	} > $TEST_DIR/filename
	{
		echo "niao mi mento ciao"
		echo "mi nato sono mi io"
		echo "miao micio sono mi"
	} > $TEST_DIR/emptys1
	{
		echo "niao mi mento ciao"
		echo "mi nato sono mi io"
		echo "miao micio sono mi"
	} > $TEST_DIR/emptys2
	{
		echo "niao mi mento ciao"
		echo "mi nato sono mi io"
		echo "miao micio sono mi"
	} > $TEST_DIR/sameparam
	{
		echo "niao mi mi mi mento ciao"
		echo "mi nato sono mi io"
		echo "miao micio sono mi"
	} > $TEST_DIR/s1s1s1
	{
		echo "mi niao mi mi mi mento ciao"
		echo "mi nato sono mi io"
		echo "miao micio sono mi"
	} > $TEST_DIR/startendfile
	{
		echo "@abc# $abc% ^abc& *abc( abc)abc"
	} > $TEST_DIR/specialchar
}

delete_replace() {
	rm -f $TEST_DIR/*.replace
}

test_function() {
	filename=$1
	s1=$2
	s2=$3
	echo -e "\n Testing: ${filename##*/} s1='$s1' s2='$s2'"
	if [ $# -eq 3 ]; then
		$REPLACED_BIN "$filename" "$s1" "$s2"
	elif [ $# -eq 2 ]; then
		$REPLACED_BIN "$filename" "$s1"
	elif [ $# -eq 1 ]; then
		$REPLACED_BIN "$filename"
	else
		$REPLACED_BIN
	fi;
	output_file_expected="${filename}.replace"
	if [ -f "$filename" ] && [ -n "$s1" ]; then
		if [ ! -f "$output_file_expected" ]; then
			echo -e "${RED} .replace file not created!${RESET}"
			return 1;
		else
			echo -e "${GREEN} Output file created.${RESET}"
		fi;
	fi;
}


generate_file
delete_replace

#All right
test_function $TEST_DIR/filename mi me

#Argument errors
test_function
test_function $TEST_DIR/one_arg
test_function $TEST_DIR/two_args s1

#Non-existent file
test_function $TEST_DIR/nofile s1 s2

#Empty file
test_function $TEST_DIR/emptyfile mi me

#Empty s1
test_function $TEST_DIR/emptys1 "" me

#Empty s2 (should remove all occurrences of s1)
test_function $TEST_DIR/emptys2 mi ""

#s1 equals s2 (no change)
test_function $TEST_DIR/sameparam mi mi

#Multiple s1 on the same line
test_function $TEST_DIR/s1s1s1 mi mo

#Overlapping occurrences ("aa" "x" in "aaa" = "xa")
test_function $TEST_DIR/onematch aa x

#s1 at the biginning and end of file
test_function $TEST_DIR/startendfile mi mm

#Special characters in file
test_function $TEST_DIR/specialchar "#" !

#Very long line
test_function $TEST_DIR/linelong mi ga

#input file already ends in .replace
#test_function $TEST_DIR/file.replace io peo

