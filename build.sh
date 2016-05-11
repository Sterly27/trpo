mkdir bin
cd bin
qmake-qt5 ../Crypt.pro
make

for i in *.o
do
	mv $i ../obj/
done

for i in *.h
do
	rm $i
done

for i in *.cpp
do
	rm $i
done

rm Makefile
cd ..
make -f Makefile~2
