#! /bin/bash

for i in pcc-libs pcc
do
	cd $i
	./configure
	make -j && make install
	cd ..
	cp pcc/cc/ccom/ccom pcc/cc/cc/
	cp pcc/cc/cpp/cpp pcc/cc/cc/
done
