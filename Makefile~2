#DON'T EDIT THIS  FILE! PLEASE!

SRC_PATH = src

root_include_dir := thirdparty

all: test

test: caesar morze vigi
	g++ ./test/main.cpp ./obj/crypt_func.o ./obj/func_morze.o ./obj/func_crpt_vigi.o -o ./bin/tests/tests

caesar: 
	g++ -c ./src/crypt_func.cpp -o ./obj/crypt_func.o

morze:
	g++ -c ./src/func_morze.cpp -o ./obj/func_morze.o

vigi:
	g++ -c ./src/func_crpt_vigi.cpp -o ./obj/func_crpt_vigi.o
