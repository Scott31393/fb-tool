# Linux Framebuffer tool to color line on the screen


## Dependencies

Install following pagages to cross-compile for arm64:

## ARM 32bit toolchain
<pre>
$ sudo apt-get install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf
</pre>

## ARM 64bit toolchain
<pre>
$ sudo apt-get install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu
Step 4: Install package dependencies
</pre>

## Required packages

<pre>
$ sudo apt-get install build-essential autoconf libtool cmake pkg-config git python-dev swig3.0 libpcre3-dev nodejs-dev
</pre>

## Clone and Compile

Clone and compile this tool using following command:

<pre>
$ git clone https://github.com/Scott31393/fb-tool.git 
$ cd fb-tool/
$ chmod 777 compile.sh
$ ./compile.sh
</pre>

Put fb-tool inside your linux system on board (arm64), then run:
<pre>
./fb-tool
</pre>

follow the log on the screen.


