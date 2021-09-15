#!/bin/bash
MODFILE=file
if [ ! -e $MODFILE ]
then
	echo 0 > $MODFILE
fi
LOCKFILE=$1.lock
echo -e "LOCKFILE: $LOCKFILE"
while ! ln $MODFILE $LOCKFILE 
do
	echo "SLEEPING"
	sleep 1  
done
LASTNUM=$(tail -n 1 $MODFILE)
echo -e "$(($LASTNUM+1))" >> $LOCKFILE
rm -f $LOCKFILE
