mkdir bin
cd bin

if [ "$1" == "-l" ] || [ "$2" == "-l" ] || [ "$3" == "-l" ]
then
	qmake-qt5 ../Crypt.pro
	make
	mkdir Linux
	mv Crypt ./Linux/Crypt
fi

if  [ "$1" == "-w" ] || [ "$2" == "-w" ] || [ "$3" == "-w" ]
then
    mingw32-qmake-qt5 ../Crypt.pro
    make
    rm -r debug
    mv release Windows
    cd Windows
	for i in *.o
	do
	rm -f $i
	done
	rm -f moc_*
    cd ..
fi

for i in *.o
do
    if [ $i ] 
    then
	mv -f $i ../obj/
       fi
done

for i in *.*
do
	rm -f $i
done

for i in Makefile*
do
	rm -f Makefile
done


if  [ "$1" == "-notest" ] || [ "$2" == "-notest" ] || [ "$3" == "-notest" ] 
then
    echo Job done
else
    mkdir tests
    cd ..
    make -f Makefile~2
    echo Job done
fi

