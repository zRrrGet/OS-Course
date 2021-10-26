echo "Mikhail" > _ex3.txt

chmod ugo-x _ex3.txt
ls -l _ex3.txt  > ex3.txt

chmod uo+rwx _ex3.txt >> ex3.txt
ls -l _ex3.txt  >> ex3.txt

chmod g=u _ex3.txt
ls -l _ex3.txt  >> ex3.txt

echo "660 means that owner and group members can write and read the file, others can't" >> ex3.txt
echo "775 means owner have all permissions, group members have all permisions, others can read and execute" >> ex3.txt
echo "777 means everybody has all permissions" >> ex3.txt
