#!/bin/sh

#	SCRIPT TO BUILD ARC-ELF32 TOOLKIT
#	---------------------------------

# Invocation Syntax
#	build_elf32.sh	<INSTALLDIR>

# INSTALLDIR = Directory where arc-elf32- toolkit will be installed.

INSTALLDIR=$1

# Building the simulator will fail if the user has their SHELL as csh, et al.
# By forcing this in the environment, sim/common/genmloop.sh invoking ${SHELL}
# will always invoke /bin/sh properly.
SHELL=/bin/sh
export SHELL

#build binutils
rm -rf binutils/build && mkdir binutils/build
cd binutils/build
../src/configure --prefix=$INSTALLDIR --target=arc-elf32 --disable-werror  > ../../log.txt 2>> ../../log.txt
make -j4 >> ../../log.txt 2>> ../../log.txt
make install  >> ../../log.txt 2>> ../../log.txt
cd ../..

#add the newly created binutils to the path
export PATH=$INSTALLDIR/bin:$PATH
export AR_FOR_TARGET=arc-elf32-ar
export AS_FOR_TARGET=arc-elf32-as
export LD_FOR_TARGET=arc-elf32-ld
export NM_FOR_TARGET=arc-elf32-nm
export RANLIB_FOR_TARGET=arc-elf32-ranlib

#build gcc
rm -rf gcc/build && mkdir gcc/build
cd gcc/build
../src/configure --target=arc-elf32 --prefix=$INSTALLDIR --with-headers --enable-multilib --with-newlib --enable-languages=c,c++ --disable-shared  >> ../../log.txt 2>> ../../log.txt
make -j4 >> ../../log.txt 2>> ../../log.txt
make install  >> ../../log.txt 2>> ../../log.txt
cd ../..

# Copy include/libs
cp -r $INSTALLDIR/include/c++ $INSTALLDIR/arc-elf32/include/
cp $INSTALLDIR/lib/libs*.a $INSTALLDIR/arc-elf32/lib/
cp $INSTALLDIR/lib/arc700/libs*.a $INSTALLDIR/arc-elf32/lib/arc700/

#build insight
rm -rf insight/build && mkdir insight/build
cd insight/build
../src/configure --target=arc-elf32 --prefix=$INSTALLDIR --disable-werror  >> ../../log.txt 2>> ../../log.txt
make -j4 >> ../../log.txt 2>> ../../log.txt
make install  >> ../../log.txt 2>> ../../log.txt
cd ../..



