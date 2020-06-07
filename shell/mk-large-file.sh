#!/bin/bash

function usage {
  echo “\n...USAGE ERROR...\n”
  echo “\nUSAGE: $SCRIPT_NAME <number_of_lines_to_create>\n”
}

################################################
# Check for the correct number of parameters
################################################
if (( $# != 1 )) # Looking for exactly one parameter
then
  usage # Usage error was made
  exit 1 # Exit on a usage error
fi

################################################
# Define files and variables here
################################################
LINE_LENGTH=80 # Number of characters per line
OUT_FILE=./bigfile # New file to create

>$OUT_FILE # Initialize to a zero-sized file
SCRIPT_NAME=$(basename $0) # Extract the name of the script
TOTAL_LINES=$1 # Total number of lines to create
LINE_COUNT=0 # Character counter
CHAR=X # Character to write to the file

################################################
# BEGINNING of MAIN
################################################
while ((LINE_COUNT < TOTAL_LINES)) # Specified by $1
do
  CHAR_COUNT=0 # Initialize the CHAR_COUNT to zero on every new line
  while ((CHAR_COUNT < LINE_LENGTH)) # Each line is fixed length
  do
    printf "${CHAR}" >> $OUT_FILE # Echo a single character
    ((CHAR_COUNT = CHAR_COUNT + 1)) # Increment the character counter
  done
  ((LINE_COUNT = LINE_COUNT + 1)) # Increment the line counter
  echo>>$OUT_FILE # Give a newline character
done
