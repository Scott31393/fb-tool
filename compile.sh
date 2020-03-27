#Compile .c script and put it into targetfs

aarch64-linux-gnu-gcc fb-tool.c -o fb-tool
sudo cp fb-tool /targetfs/home/root/
echo "Done"
