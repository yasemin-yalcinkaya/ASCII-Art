CompileAndRun:Program Run

Program: class main
	g++ ./lib/class.o ./lib/main.o -o ./bin/program
	 

class:
	g++ -I "./include" -c ./src/class.cpp -o ./lib/class.o
main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o

Run:
	./bin/program.exe
