#NO EDIT THIS  FILE! PLEAASE!

SRC_PATH = src

root_include_dir := thirdparty

all: Ctest program testilo

Ctest: Func
	g++ -c ./thirdparty/compHead.cpp ./test/test.cpp -o ./obj/ctest.o

Func:
	g++ -c ./src/compFunc.cpp -o ./obj/Func.o


program: crypt_func.o func_crpt_vigi.o func_morze.o main
	g++  ./obj/crypt_func.o ./obj/func_crpt_vigi.o ./obj/func_morze.o ./obj/crypt.o -o ./bin/program


main: ./src/crypt.cpp
	g++ -c ./src/crypt.cpp -o ./obj/crypt.o
	

crypt_func.o: ./src/crypt_func.cpp
	g++ -c ./src/crypt_func.cpp -o ./obj/crypt_func.o


func_crpt_vigi.o: ./src/func_crpt_vigi.cpp
	g++ -c ./src/func_crpt_vigi.cpp -o ./obj/func_crpt_vigi.o


func_morze.o: ./src/func_morze.cpp
	g++ -c ./src/func_morze.cpp -o ./obj/func_morze.o


testilo:
	g++ ./obj/func_morze.o ./obj/ctest.o ./obj/Func.o -o ./bin/tests/tmorze