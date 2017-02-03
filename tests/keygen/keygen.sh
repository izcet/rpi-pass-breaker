#!/bin/bashi

CFG=".cfg"

if [ ! -f $CFG ] ; then
	echo "configuration file \"$CFG\" does not exist."
	exit
fi

while read -r line || [[ -n "$line" ]] ; do
	if  echo $line | grep -v -e "^#" -e "^$" > /dev/null  ; then
		array[${#array[*]}]=$line
	fi
done < "$CFG"

KEYS="${array[0]}"
DATA="${array[1]}"
QUES="${array[3]}"
C_DIR="${array[4]}"
C_LIB="${array[5]}"
C_MAIN="${array[6]}"
C_H="${array[7]}"
EXEC="${array[8]}"
NAME="${array[9]}"

# the following assumes the above code is correct in the mapping of the values to the names
# the following also assumes all the directories exist at the locations specified


LOG=".log.keygen"
CUR=".currentuser"

# TODO: include user verification functionality
echo "Enter your username:"
read USR

if [ -f "$KEYS/.key.$USR" ] ; then
	echo "A key already exists for user '$USR'"
	exit
fi

echo "\nEnter a randomization string:"
read STR

echo "$(date)" >> $LOG
echo "New key generated for user '$USR' with randomization string \"$STR\"\n" >> $LOG

echo "" # for the newline

if [ ! -f .$EXEC.$NAME ] ; then
	gcc -Wall -Werror -Wextra $C_DIR/$C_LIB/* $C_DIR/$C_MAIN/$NAME.c -I $C_DIR/$C_H -o .$EXEC.$NAME
fi
./.$EXEC.$NAME "$STR" "$DATA/$QUES" "$KEYS/.key.$USR"

echo "$USR" > $CUR # TODO: still a thing?

exit
