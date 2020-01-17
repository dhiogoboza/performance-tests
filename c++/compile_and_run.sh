EXE_NAME=`echo $1 | cut -f 1 -d '.'`
mkdir -p build
g++ $1 -o build/$EXE_NAME
cd build
./$EXE_NAME $@
