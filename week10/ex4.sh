mkdir tmp
echo "Mikhail" > tmp/file1
echo "Mikhail" > tmp/file2
ln tmp/file1 tmp/link1
gcc ex4.c -o ex4
./ex4
