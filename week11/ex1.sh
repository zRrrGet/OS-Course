IMG=lofs.img
LOFSD=lofsdiska
dd if=/dev/zero of=$IMG bs=1M count=50
losetup -fP $IMG
sudo mkfs.ext4 ./$IMG
mkdir $LOFSD
mount -o loop $IMG $LOFSD
df -hP $LOFSD