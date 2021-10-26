mkdir ../week01
echo "Mikhail" > ../week01/file.txt
mkdir ../week10
link ../week01/file.txt  _ex2.txt
node=($(ls -i _ex2.txt));
find ../week01/file.txt -inum $node > ex2.txt
cp ../week01/file.txt file.txt
find ../week01/file.txt -inum $node -exec rm {} \; >> ex2.txt
