#!/bin/bash
echo "start compiling..."
options="-std=c++11 -DASIO_STANDALONE -DASIO_DISABLE_IOCP -D__NO_INLINE__ -I$1 -c $1/main.cpp -o $1/tmp/tmp.o"
echo "compile options ---> $options"
mkdir tmp
gcc $options &>>$1/precompile.log
cd tmp
gcc -o $1/masterserver $1/tmp/tmp.o -lstdc++ &>>$1/compile.log
cd ../
echo "compilation is now complete"