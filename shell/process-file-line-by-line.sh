#!/bin/bash

function usage {
  echo "\n...USAGE ERROR...\n"
  echo "\nUSAGE: $SCRIPT_NAME <filename>\n"
}

if (( $# != 1 )) 
then
  usage 
  exit 1 
fi

SCRIPT_NAME=$(basename $0)
FILENAME=$1

function while_read_line
{
  echo "In ${FUNCNAME[0]}..."
  cat $FILENAME | while read -r LINE
  do
    echo "$LINE"
  done
}

function while_read_line_bottom
{
  echo "In ${FUNCNAME[0]}..."
  while read -r LINE
  do
    echo "$LINE"
  done < $FILENAME
}

while_read_line
while_read_line_bottom

