#!/bin/bash
LOFSD=lofsdiska
EX=ex2.c
sudo echo 'Mikhail' > $LOFSD/file1.txt
sudo echo 'Panimash' > $LOFSD/file2.txt
sudo cp $EX $LOFSD
sudo gcc $LOFSD/$EX -o $LOFSD/ex2.out
gcc $EX -o ex2.out
if [ ! -d $LOFSD/bin ]
then
	sudo mkdir $LOFSD/bin
fi
sudo cp /bin/bash $LOFSD/bin
sudo cp /bin/ls $LOFSD/bin
sudo cp /bin/cat $LOFSD/bin
sudo cp /bin/echo $LOFSD/bin
if [ ! -d $LOFSD/lib ]
then
	sudo mkdir $LOFSD/lib
	sudo mkdir $LOFSD/lib64
	sudo mkdir $LOFSD/lib/x86_64-linux-gnu
fi
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 $LOFSD/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libc.so.6 $LOFSD/lib/x86_64-linux-gnu
sudo cp /lib64/ld-linux-x86-64.so.2 $LOFSD/lib64
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 $LOFSD/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 $LOFSD/lib/x86_64-linux-gnu
echo 'chroot:' > ex2.txt
sudo chroot $LOFSD ./ex2.out >> ex2.txt
echo '\n\nwithout chroot:' >> ex2.txt
./ex2.out >> ex2.txt