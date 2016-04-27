ifeq ($(OSTYPE),"linux-gnu")
all: program


program: crypt_func.o func_crpt_vigi.o func_morze.o int_num.o main
	g++  ./obj/crypt_func.o ./obj/func_crpt_vigi.o ./obj/func_morze.o ./obj/int_num.o ./obj/crypt.o -o ./bin/program


main:
	g++ -c ./src/crypt.cpp -o ./obj/crypt.o

crypt_func.o: 
	g++ -c ./src/crypt_func.cpp -o ./obj/crypt_func.o


func_crpt_vigi.o:
	g++ -c ./src/func_crpt_vigi.cpp -o ./obj/func_crpt_vigi.o


func_morze.o: 
	g++ -c ./src/func_morze.cpp -o ./obj/func_morze.o

int_num.o:
	g++ -c ./src/int_num.cpp -o ./obj/int_num.o
else

all: program


program: crypt_func.o func_crpt_vigi.o func_morze.o int_num.o main
	g++  ./obj/crypt_func.o ./obj/func_crpt_vigi.o ./obj/func_morze.o ./obj/int_num.o ./obj/crypt.o -o ./bin/program.exe


main:
	g++ -c ./src/crypt.cpp -o ./obj/crypt.o

crypt_func.o: 
	g++ -c ./src/crypt_func.cpp -o ./obj/crypt_func.o


func_crpt_vigi.o:
	g++ -c ./src/func_crpt_vigi.cpp -o ./obj/func_crpt_vigi.o


func_morze.o: 
	g++ -c ./src/func_morze.cpp -o ./obj/func_morze.o

int_num.o:
	g++ -c ./src/int_num.cpp -o ./obj/int_num.o
endif
